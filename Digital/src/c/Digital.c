#include <pebble.h> 
static Window *s_main_window;
static TextLayer *s_time_layer;
// Declare globally
static GFont s_time_font;
static GFont s_weather_font;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;
static TextLayer *s_weather_layer;
	  
static void update_time() {
	// Get a tm structure
	  time_t temp = time(NULL);
	  struct tm *tick_time = localtime(&temp);
	  
	  // Write the current hours and minutes into a buffer
	  static char s_buffer[8];
	  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style()  ? "%H:%M" : "%I:%M", tick_time);
	  
	  // Display this time on the Textlayer
	  text_layer_set_text(s_time_layer, s_buffer);  
}

static void main_window_load(Window *window) {
	// Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
	// Create GBitmap
	s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
	
	// Create BitmapLayer to display the GBitmap
	s_background_layer = bitmap_layer_create(bounds);
  
	//Set the bitmap onto the layer and add to the window
	bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
	layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));
  
  
	//Create the textLayer with specific bounds
	s_time_layer  = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(58,52), bounds.size.w, 50));
	
	// Improve the layout to be more like a watchface
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_text_color(s_time_layer, GColorBlack);
	text_layer_set_text(s_time_layer, "00:00");
	
	// Appy to TextLayer
	//s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_PERFECT_DOS_48));
	//text_layer_set_font(s_time_layer, s_time_font);
	text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
	
	// Create temperature layer
	s_weather_layer = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(125, 120), bounds.size.w, 25));
	
	// Style the text
	text_layer_set_background_color(s_weather_layer, GColorClear);
	text_layer_set_text_color(s_weather_layer, GColorWhite);
	text_layer_set_text_alignment(s_weather_layer, GTextAlignmentCenter);
	text_layer_set_text(s_weather_layer, "Loading...");
	
	// Create second custom font, apply it and add to Window
  	s_weather_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_PERFECT_DOS_20));
	text_layer_set_font(s_weather_layer, s_weather_font);
	
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer));
}

static void main_window_unload(Window *window) {
	//Destroy Textlayer
	text_layer_destroy(s_time_layer);
	//Destroy Window
	window_destroy(s_main_window);
	// Unload GFont
	fonts_unload_custom_font(s_time_font);
	//Destroy GBitmap
	gbitmap_destroy(s_background_bitmap);
	// Destroy BitmapLayer
	bitmap_layer_destroy(s_background_layer);
	// Destroy weather elements
	text_layer_destroy(s_weather_layer);
	fonts_unload_custom_font(s_weather_font);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
	// Register with TickTimer Service
	tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
	
	// Make sure the time is displayed from the start
	update_time();
	
	// Get weather update every 30 minutes
	if (tick_time->tm_min % 30 == 0) {
	APP_LOG(APP_LOG_LEVEL_ERROR, "tick_handler ... checking weather");
		// Begin dictionary
		DictionaryIterator*iter;
		app_message_outbox_begin(&iter);
		
		// Add a key-value pair
		dict_write_uint8(iter, 0, 0);
		
		// Send the message!
		app_message_outbox_send();
	}
}


// Adding methods to handle messaging ...

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {

	// Store incoming information
static char temperature_buffer[8];
static char conditions_buffer[32];
static char weather_layer_buffer[32];

//Read tuples for data
Tuple *temp_tuple = dict_find(iterator, MESSAGE_KEY_TEMPERATURE);
Tuple *conditions_tuple = dict_find(iterator, MESSAGE_KEY_CONDITIONS);
	APP_LOG(APP_LOG_LEVEL_ERROR, "tick_handler!");
// If all data is available, use it
if (temp_tuple && conditions_tuple) {
		APP_LOG(APP_LOG_LEVEL_ERROR, "tick_handler inside if");
	  snprintf(temperature_buffer, sizeof(temperature_buffer), "%dºF", (int) temp_tuple->value->int32);
	  snprintf(conditions_buffer, sizeof(conditions_buffer), "%s", conditions_tuple->value->cstring);
	  // Assemble full string and display
	  snprintf(weather_layer_buffer, sizeof(weather_layer_buffer), "%s, %s", temperature_buffer, conditions_buffer);
	  text_layer_set_text(s_weather_layer, weather_layer_buffer);
}
}

static void inbox_dropped_callback(AppMessageResult reason, void *context)  {
		APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
		APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
			APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

static void init() {
	//  Create main window element and assign to pointer
	s_main_window = window_create();
	window_set_background_color(s_main_window, GColorBlack);
	
	// Set handlers to manage the elements inside the window
	window_set_window_handlers(s_main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload
	});
	
	// Show the Window on the watch, with animated = true
	window_stack_push(s_main_window, true);
	
	tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
	
	// Register callbacks
	app_message_register_inbox_received(inbox_received_callback);
	
	// Open AppMessageResult
	const int inbox_size =128;
    const int outbox_size = 128;

	app_message_open(inbox_size, outbox_size);	
	app_message_register_inbox_dropped(inbox_dropped_callback);
	app_message_register_outbox_failed(outbox_failed_callback);
	app_message_register_outbox_sent(outbox_sent_callback);
	
	update_time();
	}

static void deinit() {
	  // Destroy Window
	  window_destroy(s_main_window);
	
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}

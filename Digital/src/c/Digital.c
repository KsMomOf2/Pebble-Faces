#include <pebble.h>
// TODO Need to add comments
static Window *s_main_window;
static TextLayer *s_time_layer;
static GFont s_time_font;
static GFont s_weather_font;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;
static TextLyer *s_weather_layer;

static void update_time() {
	  time_t temp = time(NULL);
	  struct tm *tick_time = localtime(&temp);
	  
	  static char s_buffer[8];
	  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style()  ? "%H:%M" : "%I:%M", tick_time);
	  text_layer_set_text(s_time_layer, s_buffer);
}
/*
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
	  update_time();
}
	  */

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  s_time_layer  = text_layer_create(GRect(0, PBL_IF_ROUND_ELSE(58,52), bounds.size.w, 50));
  
  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  s_background_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));
  
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "00:00");
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_PERFECT_DOS_48));
  text_layer_set_font(s_time_layer, s_time_font);
//  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
	
	// Create temperature layer
	s_weather_layer = textlayer_create(GRect(0, PBL_IF_ROUND_ELSE(125, 120), bounds.size.w, 25));
	
	// Style the text
	text_layer_set_background_color(s_weather_leayer, GColorClear);
	text_layer_set_text_color(s_weather_layer, GColorWhite);
	text_layer_set_text_alignment(s_weather_layer, GTextAlignmentCenter);
	text_layer_set_text(s_weather_layer, "Loading...");
	
	// Create second custom font, apply it and add to Window
	s_weather_font = fons_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_PERFECT_DOS_34));
	text_layer_set_font(s_weather_layer, s_weather_font);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer));
	
}

static void main_window_unload(Window *window) {
	text_layer_destroy(s_time_layer);
	window_destroy(s_main_window);
	fonts_unload_custom_font(s_time_font);
	gbitmap_destroy(s_background_bitmap);
	bitmap_layer_destroy(s_background_layer);
	// Destroy weather elements
	text_layer_destroy(s_weather_layer);
	fonts_unload_custom_font(s_weather_font);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
	update_time();
}

static void init() {
	s_main_window = window_create();
	window_set_background_color(s_main_window, GColorBlack);
	window_set_window_handlers(s_main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload
	});
	window_stack_push(s_main_window, true);
	tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
	
	update_time();
	}

static void deinit() {
	
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}

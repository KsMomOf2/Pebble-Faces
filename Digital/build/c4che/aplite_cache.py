AR = 'arm-none-eabi-ar'
ARFLAGS = 'rcs'
AS = 'arm-none-eabi-gcc'
BINDIR = '/usr/local/bin'
BLOCK_MESSAGE_KEYS = []
BUILD_DIR = 'aplite'
BUILD_TYPE = 'app'
BUNDLE_BIN_DIR = 'aplite'
BUNDLE_NAME = 'Digital.pbw'
CC = ['arm-none-eabi-gcc']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '7', '2')
CFLAGS = ['-std=c99', '-mcpu=cortex-m3', '-mthumb', '-ffunction-sections', '-fdata-sections', '-g', '-fPIE', '-Os', '-D_TIME_H_', '-Wall', '-Wextra', '-Werror', '-Wno-unused-parameter', '-Wno-error=unused-function', '-Wno-error=unused-variable']
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_cshlib = ['-fPIC']
CPPPATH_ST = '-I%s'
DEFINES = ['RELEASE', 'PBL_PLATFORM_APLITE', 'PBL_BW', 'PBL_RECT', 'PBL_COMPASS', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168', 'PBL_SDK_3']
DEFINES_ST = '-D%s'
DEST_BINFMT = 'elf'
DEST_CPU = 'arm'
DEST_OS = 'linux'
INCLUDES = ['aplite']
LD = 'arm-none-eabi-ld'
LIBDIR = '/usr/local/lib'
LIBPATH_ST = '-L%s'
LIB_DIR = 'node_modules'
LIB_JSON = []
LIB_ST = '-l%s'
LINKFLAGS = ['-mcpu=cortex-m3', '-mthumb', '-Wl,--gc-sections', '-Wl,--warn-common', '-fPIE', '-Os']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINK_CC = ['arm-none-eabi-gcc']
MESSAGE_KEYS = {u'CONDITIONS': 10001, u'TEMPERATURE': 10000}
MESSAGE_KEYS_DEFINITION = '/home/ksmomof2/pebble-dev/pebble-faces/Digital/build/src/message_keys.auto.c'
MESSAGE_KEYS_HEADER = '/home/ksmomof2/pebble-dev/pebble-faces/Digital/build/include/message_keys.auto.h'
MESSAGE_KEYS_JSON = '/home/ksmomof2/pebble-dev/pebble-faces/Digital/build/js/message_keys.json'
NODE_PATH = '/home/ksmomof2/.pebble-sdk/SDKs/current/node_modules'
PEBBLE_SDK_COMMON = '/home/ksmomof2/.pebble-sdk/SDKs/current/sdk-core/pebble/common'
PEBBLE_SDK_PLATFORM = '/home/ksmomof2/.pebble-sdk/SDKs/current/sdk-core/pebble/aplite'
PEBBLE_SDK_ROOT = '/home/ksmomof2/.pebble-sdk/SDKs/current/sdk-core/pebble'
PLATFORM = {'TAGS': ['aplite', 'bw', 'rect', 'compass', '144w', '168h'], 'MAX_FONT_GLYPH_SIZE': 256, 'ADDITIONAL_TEXT_LINES_FOR_PEBBLE_H': [], 'MAX_APP_BINARY_SIZE': 65536, 'MAX_RESOURCES_SIZE': 524288, 'MAX_APP_MEMORY_SIZE': 24576, 'MAX_WORKER_MEMORY_SIZE': 10240, 'NAME': 'aplite', 'BUNDLE_BIN_DIR': 'aplite', 'BUILD_DIR': 'aplite', 'MAX_RESOURCES_SIZE_APPSTORE_2_X': 98304, 'MAX_RESOURCES_SIZE_APPSTORE': 131072, 'DEFINES': ['PBL_PLATFORM_APLITE', 'PBL_BW', 'PBL_RECT', 'PBL_COMPASS', 'PBL_DISPLAY_WIDTH=144', 'PBL_DISPLAY_HEIGHT=168']}
PLATFORM_NAME = 'aplite'
PREFIX = '/usr/local'
PROJECT_INFO = {'appKeys': {u'CONDITIONS': 10001, u'TEMPERATURE': 10000}, u'sdkVersion': u'3', u'displayName': u'Digital', u'uuid': u'fa6ef243-e225-44d9-acce-6389a66f033c', u'messageKeys': {u'CONDITIONS': 10001, u'TEMPERATURE': 10000}, 'companyName': u'KsMomOf2', u'enableMultiJS': True, u'targetPlatforms': [u'aplite', u'basalt', u'chalk', u'diorite'], u'capabilities': [u'location'], 'versionLabel': u'1.0', 'longName': u'Digital', 'shortName': u'Digital', u'watchapp': {u'watchface': True}, u'resources': {u'media': [{u'type': u'font', u'name': u'FONT_PERFECT_DOS_48', u'file': u'fonts/perfect-dos-vga.ttf', u'compatibility': u'2.7'}, {u'type': u'font', u'name': u'FONT_PERFECT_DOS_20', u'file': u'fonts/perfect-dos-vga.ttf', u'compatibility': u'2.7'}, {u'type': u'bitmap', u'name': u'IMAGE_BACKGROUND', u'file': u'images/background.png'}]}, 'name': u'Digital'}
REQUESTED_PLATFORMS = [u'aplite', u'basalt', u'chalk', u'diorite']
RESOURCES_JSON = [{u'type': u'font', u'name': u'FONT_PERFECT_DOS_48', u'file': u'fonts/perfect-dos-vga.ttf', u'compatibility': u'2.7'}, {u'type': u'font', u'name': u'FONT_PERFECT_DOS_20', u'file': u'fonts/perfect-dos-vga.ttf', u'compatibility': u'2.7'}, {u'type': u'bitmap', u'name': u'IMAGE_BACKGROUND', u'file': u'images/background.png'}]
RPATH_ST = '-Wl,-rpath,%s'
SANDBOX = False
SDK_VERSION_MAJOR = 5
SDK_VERSION_MINOR = 78
SHLIB_MARKER = None
SIZE = 'arm-none-eabi-size'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = None
STLIB_ST = '-l%s'
SUPPORTED_PLATFORMS = ['diorite', 'aplite', 'basalt', 'chalk', 'emery']
TARGET_PLATFORMS = ['diorite', 'chalk', 'basalt', 'aplite']
TIMESTAMP = 1544878797
USE_GROUPS = True
VERBOSE = 0
WEBPACK = '/home/ksmomof2/.pebble-sdk/SDKs/current/node_modules/.bin/webpack'
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
macbundle_PATTERN = '%s.bundle'

import os
import platform

OS_NAME=platform.system()
APP_ROOT = os.path.normpath(os.getcwd())
APP_3RD_ROOT = os.path.join(APP_ROOT, '3rd')
APP_BIN_DIR=os.path.join(APP_ROOT, 'bin')
APP_LIB_DIR=os.path.join(APP_ROOT, 'lib')

TK_ROOT = os.path.normpath(os.getcwd()+'/../awtk')
TK_SRC = os.path.join(TK_ROOT, 'src')
TK_3RD_ROOT = os.path.join(TK_ROOT, '3rd')
TK_BIN_DIR=os.path.join(TK_ROOT, 'bin')
TK_LIB_DIR=os.path.join(TK_ROOT, 'lib')

os.environ['APP_ROOT'] = APP_ROOT;
os.environ['BIN_DIR'] = APP_BIN_DIR;
os.environ['LIB_DIR'] = APP_LIB_DIR;

os.environ['TK_ROOT'] = TK_ROOT;
os.environ['TK_BIN_DIR'] = TK_BIN_DIR;
os.environ['TK_LIB_DIR'] = TK_LIB_DIR;

OS_LIBPATH=[]
OS_CPPPATH=[]
OS_FLAGS='-g -Wall'
OS_SUBSYSTEM_CONSOLE=''
OS_SUBSYSTEM_WINDOWS=''
OS_LINKFLAGS=''


COMMON_CCFLAGS = ' -DHAS_STD_MALLOC -DHAS_STDIO -DWITH_SDL -DWITH_FS_RES '
if OS_NAME == 'Darwin':
  OS_LIBS=['stdc++', 'pthread', 'm']
  OS_LINKFLAGS='-framework OpenGL'
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -D__APPLE__ -DHAS_PTHREAD -DMACOS'

elif OS_NAME == 'Linux':
  OS_LIBS = ['GL', 'stdc++', 'pthread', 'm', 'dl']
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DLINUX -DHAS_PTHREAD'

elif OS_NAME == 'Windows':
  OS_LIBS=['gdi32', 'user32','winmm.lib','imm32.lib','version.lib','shell32.lib','ole32.lib','Oleaut32.lib','Advapi32.lib']
  OS_FLAGS='-DWIN32 -D_WIN32 -DWINDOWS /EHsc -D_CONSOLE  /DEBUG /Od  /FS /Z7 '
  COMMON_CCFLAGS = COMMON_CCFLAGS + ' -DSDL_REAL_API -DSDL_HAPTIC_DISABLED -DSDL_SENSOR_DISABLED -DSDL_JOYSTICK_DISABLED '
  OS_LINKFLAGS='/MACHINE:X64 /DEBUG'
  OS_SUBSYSTEM_CONSOLE='/SUBSYSTEM:CONSOLE  '
  OS_SUBSYSTEM_WINDOWS='/SUBSYSTEM:WINDOWS  '
  
LIBS=['awtk', 'gpinyin', 'awtk', 'linebreak', 'nanovg', 'agge', 'SDL2', 'glad'] + OS_LIBS

CCFLAGS=OS_FLAGS + COMMON_CCFLAGS 

CPPPATH=[
  APP_ROOT,
  TK_ROOT, 
  TK_SRC, 
  TK_3RD_ROOT, 
  APP_3RD_ROOT,
  os.path.join(TK_SRC, 'ext_widgets')]

LIBPATH = [TK_LIB_DIR, APP_LIB_DIR]

DefaultEnvironment(CCFLAGS = CCFLAGS, 
  CPPPATH = CPPPATH,
  LIBS=LIBS,
  LINKFLAGS=OS_LINKFLAGS,
  OS_SUBSYSTEM_CONSOLE=OS_SUBSYSTEM_CONSOLE,
  OS_SUBSYSTEM_WINDOWS=OS_SUBSYSTEM_WINDOWS,
  LIBPATH=LIBPATH + OS_LIBPATH)

SConscript(['src/SConscript'])


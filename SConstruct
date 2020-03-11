import os
import sys
import platform

sys.path.insert(0, '../awtk/')
#sys.path.insert(0, '../awtk-linux-fb/')
import awtk_config as awtk

APP_ROOT    = os.path.normpath(os.getcwd())
APP_BIN_DIR = os.path.join(APP_ROOT, 'bin')
APP_LIB_DIR = os.path.join(APP_ROOT, 'lib')

os.environ['APP_ROOT'] = APP_ROOT;
os.environ['BIN_DIR'] = APP_BIN_DIR;
os.environ['LIB_DIR'] = APP_LIB_DIR;

APP_CCFLAGS = ''
APP_LINKFLAGS=''
APP_LIBPATH = [APP_LIB_DIR]
APP_LIBS = ['assets', 'sqlite3']
APP_CPPPATH=[os.path.join(APP_ROOT, '3rd')]

if awtk.has_custom_cc():
  DefaultEnvironment(
    CC=awtk.CC,
    CXX=awtk.CXX,
    LD=awtk.LD,
    AR=awtk.AR,
    STRIP=awtk.STRIP,
    CPPPATH   = awtk.CPPPATH + APP_CPPPATH,
    LINKFLAGS = awtk.LINKFLAGS + APP_LINKFLAGS,
    LIBS      = APP_LIBS + awtk.LIBS,
    LIBPATH   = APP_LIBPATH + awtk.LIBPATH,
    CCFLAGS   = APP_CCFLAGS + awtk.CCFLAGS, 
    OS_SUBSYSTEM_CONSOLE=awtk.OS_SUBSYSTEM_CONSOLE,
    OS_SUBSYSTEM_WINDOWS=awtk.OS_SUBSYSTEM_WINDOWS)
else:
  DefaultEnvironment(
    CPPPATH   = awtk.CPPPATH + APP_CPPPATH,
    LINKFLAGS = awtk.LINKFLAGS + APP_LINKFLAGS,
    LIBS      = APP_LIBS + awtk.LIBS,
    LIBPATH   = APP_LIBPATH + awtk.LIBPATH,
    CCFLAGS   = APP_CCFLAGS + awtk.CCFLAGS, 
    OS_SUBSYSTEM_CONSOLE=awtk.OS_SUBSYSTEM_CONSOLE,
    OS_SUBSYSTEM_WINDOWS=awtk.OS_SUBSYSTEM_WINDOWS)

SConscript(['3rd/sqlite3/SConscript', 'src/SConscript'])


# AWTK 如何集成第三方库

AWTK 集成第三方库非常简单，这里以集成 sqlite3 介绍一下具体方法。

## 一、编译第三方库

* 优先使用第三方库自己的构建方法。

* 如果第三方使用autoconf等方法构建，在Windows平台上就会遇到问题。此时可以使用scons重写构建脚本。

比如：

> 以下是给sqlite3写的scons构建脚本。

```
import os
import platform

env=DefaultEnvironment().Clone()
LIB_DIR=os.environ['LIB_DIR'];
BIN_DIR=os.environ['BIN_DIR'];

env.Library(os.path.join(LIB_DIR, 'sqlite3'), Glob("sqlite3.c"))
env.Program(os.path.join(BIN_DIR, 'sqlite3'), Glob("shell.c"))
```

> 请参考 awtk-hello 中的 [3rd/sqlite3/SConscript](https://github.com/zlgopen/awtk-hello/blob/master/3rd/sqlite3/SConscript) 

## 二、在SConstruct中引入第三方库

* 在 APP_LIBPATH 变量中加入库的路径
* 在 APP_LIBS 变量中加入库的名称。
* 在 APP_CPPPATH 变量中加头文件路径。

比如：


```
APP_CCFLAGS = ''
APP_LINKFLAGS=''
APP_LIBPATH = [APP_LIB_DIR]
APP_LIBS = ['assets', 'sqlite3']
APP_CPPPATH=[os.path.join(APP_ROOT, '3rd/sqlite3')]

DefaultEnvironment(
  LINKFLAGS = APP_LINKFLAGS + awtk.LINKFLAGS,
  CPPPATH   = APP_CPPPATH + awtk.CPPPATH,
  LIBS      = APP_LIBS + awtk.LIBS,
  LIBPATH   = APP_LIBPATH + awtk.LIBPATH,
  CCFLAGS   = APP_CCFLAGS + awtk.CCFLAGS, 
  OS_SUBSYSTEM_CONSOLE=awtk.OS_SUBSYSTEM_CONSOLE,
  OS_SUBSYSTEM_WINDOWS=awtk.OS_SUBSYSTEM_WINDOWS)
  
```

> 请参考 awtk-hello 中的 [SConstruct](https://github.com/zlgopen/awtk-hello/blob/master/SConstruct)  
  

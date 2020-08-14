import os
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS);
helper.add_libs(['sqlite3']).add_cpppath([os.path.join(helper.APP_ROOT, '3rd')]).call(DefaultEnvironment)

SConscriptFiles = ['src/SConscript', '3rd/sqlite3/SConscript']
SConscript(SConscriptFiles)

# this is the build script used by SCons
# maintained by zhangyafeikimi
#
# scons [debug==0]
#
debug = ARGUMENTS.get('debug', 1)
env=Environment()
env=env.Clone()

print 'building for %s' % env['PLATFORM']
print 'debug = %s' % debug
print 'clean = %s' % env.GetOption('clean')

env.Append(CPPPATH = ['.', 'include'])
env.Append(LIBPATH = ['.'])
env.Append(LIBS = ['leveldb'])

if env['PLATFORM'] == 'win32':
    env.Append(CPPPATH = ['port\win'])
    env.Append(CPPFLAGS = ['/DWIN32', '/DLEVELDB_PLATFORM_WINDOWS', '/DOS_WIN', '/DCOMPILER_MSVC'])
    env.Append(CCFLAGS = '/Zi /W3 /wd4996 /wd4800 /wd4355 /wd4244 /wd4018')

if env['CC'] == 'cl':
    env.Append(CCFLAGS = '/EHsc')
    if int(debug) == 1:
        env.Append(CCFLAGS = '/Od /RTC1 /MTd')
        env.Append(CPPFLAGS = '/D_DEBUG')
    else:
        env.Append(CCFLAGS = '/O2 /Oi /MT /GL /Gy')
        env.Append(CPPFLAGS = ['/DNDEBUG'])
elif env['CC'] == 'gcc':
    env.Append(CCFLAGS = '-Wall -g')
    if int(debug) == 0:
        env.Append(CCFLAGS = '-O2')


SOURCE = [
    'db/builder.cc',
    'db/c.cc',
    'db/db_impl.cc',
    'db/db_iter.cc',
    'db/dbformat.cc',
    'db/filename.cc',
    'db/log_reader.cc',
    'db/log_writer.cc',
    'db/memtable.cc',
    'db/repair.cc',
    'db/table_cache.cc',
    'db/version_edit.cc',
    'db/version_set.cc',
    'db/write_batch.cc',
    'helpers/memenv/memenv.cc',
    'table/block.cc',
    'table/block_builder.cc',
    'table/format.cc',
    'table/iterator.cc',
    'table/merger.cc',
    'table/table.cc',
    'table/table_builder.cc',
    'table/two_level_iterator.cc',
    'util/arena.cc',
    'util/cache.cc',
    'util/coding.cc',
    'util/comparator.cc',
    'util/crc32c.cc',
    'util/env.cc',
    'util/hash.cc',
    'util/histogram.cc',
    'util/logging.cc',
    'util/options.cc',
    'util/status.cc',
    'util/testharness.cc',
    'util/testutil.cc',
]

if env['PLATFORM'] == 'win32':
    SOURCE += ['port/port_win.cc', 'util/env_win.cc']

env.StaticLibrary('leveldb',
    SOURCE,
)

env.Program('corruption_test', 'db/corruption_test.cc')
env.Program('db_test', 'db/db_test.cc')
env.Program('dbformat_test', 'db/dbformat_test.cc')
env.Program('filename_test', 'db/filename_test.cc')
env.Program('log_test', 'db/log_test.cc')
env.Program('skiplist_test', 'db/skiplist_test.cc')
env.Program('version_edit_test', 'db/version_edit_test.cc')
env.Program('version_set_test', 'db/version_set_test.cc')
env.Program('write_batch_test', 'db/write_batch_test.cc')
env.Program('memenv_test', 'helpers/memenv/memenv_test.cc')
env.Program('table_test', 'table/table_test.cc')
env.Program('arena_test', 'util/arena_test.cc')
env.Program('cache_test', 'util/cache_test.cc')
env.Program('coding_test', 'util/coding_test.cc')
env.Program('crc32c_test', 'util/crc32c_test.cc')
env.Program('env_test', 'util/env_test.cc')



project('berkeley', 'cpp')

inc_dir = include_directories('include')
src = ['src/berkeley.cpp', 'src/clock.cpp']
thread_dep = dependency('threads')

executable('berkeley',
            sources : src,
            dependencies : thread_dep,
            include_directories : inc_dir)
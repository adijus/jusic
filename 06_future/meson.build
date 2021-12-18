project('factoring', 'cpp')

inc_dir = include_directories('include')
src = ['src/factoring.cpp']
thread_dep = dependency('threads')

executable('factoring',
            sources : src,
            dependencies : thread_dep,
            include_directories : inc_dir)
project('account', 'cpp')
thread_dep = dependency('threads')
inc_dir = include_directories('include')
executable('account', 'src/main.cpp', 'src/account.cpp',
	   dependencies: thread_dep,
	   include_directories: inc_dir)

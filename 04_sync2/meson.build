project('sync', 'cpp')

inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/work_packet.cpp', 'src/work_queue.cpp']
thread_dep = dependency('threads')

executable('sync', 
	    sources : src,
	    dependencies : thread_dep,
		include_directories : inc_dir)

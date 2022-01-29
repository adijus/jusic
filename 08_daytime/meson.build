# uncomment as necessary
project('08_daytime', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

 thread_dep = dependency('threads')


inc_dir = include_directories(['include',
				 get_option('cli11_include_dir'),
				 get_option('spdlog_include_dir'),
				 get_option('json_include_dir'),
				 get_option('asio_include_dir')
			       ])

# subdir('XXX')

src1 = ['src/daytime_client/main.cpp']
src2 = ['src/daytime_server/main.cpp']


executable('client',
	    sources : src1,
	    include_directories : inc_dir,
	    dependencies : thread_dep,
	    #link_with : XXX_lib
          )
          
executable('server',
            sources : src2,
            include_directories : inc_dir,
            dependencies : thread_dep,
            #link_with : XXX_lib
          )
          
 


#src = ['src/main.cpp']
#protobuf: src = ['src/main.cpp', generated]



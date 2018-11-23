require 'mkmf'

libs = ['-lspeex', '-lm']
libs.each do |lib|
  $LOCAL_LIBS << "#{lib} "
end

create_makefile('speex_decoder/speex_decoder')

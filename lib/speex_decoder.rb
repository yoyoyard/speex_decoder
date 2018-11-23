require "speex_decoder/version"
require "speex_decoder/speex_decoder"

module SpeexDecoder
  def self.test
    SpeexDecoder.decode '/Users/xiaohui/Desktop/test.speex', '/Users/xiaohui/Desktop/test.wav'
  end
end

require "speex_decoder/version"
require "speex_decoder/speex_decoder"

module SpeexDecoder
  class << self
    alias_method :origin_decode, :decode
    def decode(speex_path, wav_path)
      result = origin_decode(speex_path, wav_path)

      if result == 0
        return :success
      elsif result == 1
        raise '.speex file could not found.'
      else
        raise 'save file error for the output wav file.'
      end
    end
  end
end

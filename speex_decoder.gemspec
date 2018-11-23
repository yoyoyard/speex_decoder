lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "speex_decoder/version"

Gem::Specification.new do |spec|
  spec.name          = "speex_decoder"
  spec.version       = SpeexDecoder::VERSION
  spec.authors       = ["Xiaohui Gan"]
  spec.email         = ["286390860@qq.com"]

  spec.summary       = %q{Convert speex file into wav.}
  spec.description   = %q{Convert speex file into wav.}
  spec.homepage      = "https://github.com/yoyoyard/speex_decoder"
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^(test|spec|features)/})
  end
  spec.require_paths = ["lib"]
  spec.extensions    = %w[ext/speex_decoder/extconf.rb]

  spec.add_development_dependency "bundler", "~> 1.16"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec", "~> 3.0"
  spec.add_development_dependency 'rake-compiler', '~> 1'
end

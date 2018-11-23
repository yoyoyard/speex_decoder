require "bundler/gem_tasks"
require "rspec/core/rake_task"
require 'rake/extensiontask'

Rake::ExtensionTask.new "speex_decoder" do |ext|
  ext.lib_dir = "lib/speex_decoder"
end

RSpec::Core::RakeTask.new(:spec)

task :default => :spec

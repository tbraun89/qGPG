VAGRANT_VERSION = '2'

# TODO add boxes for Windows and OS X
# TODO add build script to run the build on each box and create
#      system packages for each box and copy the packages to
#      the dist directory when done

unix_nodes = [
  {host: 'linux32', ip: '192.168.0.100', box: 'ubuntu/trusty32'},
  {host: 'linux64', ip: '192.168.0.101', box: 'ubuntu/trusty64'},
  {host: 'osx',     ip: '192.168.0.102', box: 'jhcook/osx-yosemite-10.10'}
]

Vagrant.configure(VAGRANT_VERSION) do |config|
  # Configuration for Unix based systems
  unix_nodes.each do |node|
    config.vm.define node[:host] do |nconfig|
      nconfig.vm.box      = node[:box]
      nconfig.vm.hostname = "#{node[:host]}-vm"
      nconfig.vm.network  :private_network, ip: node[:ip]

      nconfig.vm.provider :virtualbox do |box|
        box.customize [
          'modifyvm',          :id,
          '--cpuexecutioncap', '50',
          '--memory',          '1024',
        ]
      end
    end
  end
end

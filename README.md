# qGPG

This is a GUI for GPG, the current state of this application is
in early development so there are not all functions implemented and you
may find many bugs or security issues. Use this project only for testing
before there is an release.

## Dependencies

* Qt5
* `libgpgme11`

## Deployment

The deployment for Linux, OS X and Windows will be generated with Vagrant.
The deployment script will download the box images, setup the environment,
compile the source on the boxes and create binary packages for each system
automatically. The binary packages/installers will be created in the
`release` folder for each system.

1. Install [Vagrant](https://www.vagrantup.com/) and [VirtualBox](https://www.virtualbox.org/)
2. Install the `Oracle VM VirtualBox Extension Pack`
2. Run `./deploy.sh`

## Contributing

1. Fork it (https://github.com/tbraun89/qGPG/fork)
2. Create your feature branch (`git checkout -b my_new_feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my_new_feature`)
5. Create new Pull Request

# qGPG

This is a GUI for GPG, the current state of this application is
in early development so there are not all functions implemented and you
may find many bugs or security issues. Use this project only for testing
before there is an release.

## Dependencies

* Qt5
* `libgpgme11`

## Contributing

If you want to contribute to the core please read the information below. If you want to create a Plugin please read the Wiki article about creating Plugins for qGPG and use your own repository. You can see all features that are in development in their branch. Before you start contributing to a feature check the issue tracker if there is a ticket for the feature, if not create an enhancement ticket and ask what needs to be done. If you want to create a new core feature do the same.

I use [git-flow](https://github.com/nvie/gitflow) to manage this repository, if you don't use git-flow for contributing I will have more work on merging your Pull Request. And don't forget to test your code I will only merge changes that have a good test coverage.

1. Fork it (https://github.com/tbraun89/qGPG/fork)
2. Create your feature branch (`git git flow feature start my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin feature/my-new-feature`)
5. Create new Pull Request

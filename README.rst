Plastic Logic Software Development Kit
======================================

The Plastic Logic Software Development Kit (PLSDK) is a collection of libraries
and applications specialised in **electrophoretic displays (EPD)**, also known
as **E-Paper**.  It is designed to easily evaluate the Plastic Logic EPD
technology, build demonstrators and product prototypes.  It may also be used in
a commercial product.

The **C API** defined by the PLSDK libraries provide an abstraction layer as
well as convenience functions to achieve all basic **drawing operations** and
complete **manual EPD control**.  The code is platform-independent, but
currently relies on the standard Linux kernel framebuffer and input device
driver interfaces.  It is known to work on most **GNU/Linux** distributions
(Debian, Ubuntu, Ångström) on **ARM and x86**, as well as **Android**.

**A Python package** ``plsdk`` based on the C PLSDK libraries is also available
and provides a quicker and more flexible prototyping framework.  The source
code can be found in the `pyplsdk <https://github.com/plasticlogic/pyplsdk>`_
repository.


Getting the source code
-----------------------

The PLSDK relies on ``repo`` and ``git`` to manage all its source code.  First
you will need to install ``git`` and potentially several other packages
depending on your Linux distribution.  On Debian or Ubuntu systems, run this
command::

    $ sudo apt-get install git

Then to install ``repo``, follow the instructions on the `Android Developers
page <http://source.android.com/source/downloading.html>`_.  In a nutshell::

    $ mkdir ~/bin
    $ PATH=~/bin:$PATH
    $ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
    $ chmod a+x ~/bin/repo

Then to get the latest source code from `Github
<https://github.com/plasticlogic/>`_::

    $ mkdir -p ~/src/plsdk
    $ cd ~/src/plsdk
    $ repo init -u git://github.com/plasticlogic/manifest.git
    $ repo sync

To update your source code in the future and keep up-to-date, run::

    $ repo sync

Alternatively, to get a specific release number, for example plsdk-011::

    $ repo init -m plsdk-011.xml
    $ repo sync


Building for GNU/Linux
----------------------

To cross-compile for ARM, a third-party toolchain needs to be installed first.
The a few environment variables need to be defined, which can easily be achived
with these scripts::

    $ . plsdk/fast-builder/envsetup.sh # for cross-compiling, adjust paths
    $ . plsdk/fast-builder/native-envsetup.sh # for native build

Then to build::

    $ make -j5 # adjust -j for the number of parallel builds

The output files are located in the following directories ($ARCH is the target
architecture name, typically ``arm`` or ``x86_64``)::

    out/$ARCH/bin # install in /usr/bin on the target
    out/$ARCH/lib # install in /usr/lib on the target
    out/$ARCH/include # public C header files, install in /usr/include
    out/$ARCH/python2.7 # depends on your target Python version, in /usr/lib/

Building for Android
--------------------

Building for Android is achieved with the Android Native Development Kit (NDK).
Instructions to install it can be found on the `Android NDK page
<http://developer.android.com/tools/sdk/ndk/index.html>`_.

A different repo manifest file ``android-ndk.xml`` needs to be used to build
with the Android NDK.  If the source tree has not yet been initialised, run::

    repo init -u git@github.com:plasticlogic/manifest.git -b master -m android-ndk.xml

Otherwise, to simply switch to the other manifest file::

    repo init -m android-ndk.xml
    rm -rf plsdk

Then to actually update the source tree::

    repo sync

Then to build the source code, run::

    $ ndk-build -j5

The output files can be found in the ``libs/armeabi/`` directory.

# mbpfan-josie

This is my fork of [mbpfan](https://github.com/linux-on-mac/mbpfan), itself an enhanced version of [Allan McRae mbpfan](http://allanmcrae.com/2010/05/simple-macbook-pro-fan-daemon/).

This fork is focused on **Gentoo Linux on older Intel Macs**. My current machine is a MacBook Pro 11,4 (Retina 15", mid-2015), so that's what I test on. The board is a Mac-06F11FD93F0323C5, the i7 4770HQ/16GB RAM/Intel Iris Pro 5200 one (I swapped out the stock Radeon dGPU one due to issues at the time with older AMD cards on Linux).

Other distributions and Mac models are not supported or tested by this fork. If you need broader support, use [upstream mbpfan](https://github.com/linux-on-mac/mbpfan).

## Requirements

- Gentoo Linux with OpenRC (the primary target).
- Kernel modules `applesmc` and `coretemp`.
- Root privileges to run the daemon.

Load the modules at boot with OpenRC:

```sh
# /etc/conf.d/modules
modules="applesmc coretemp"
```

If you use systemd on Gentoo instead, the installed
`/etc/modules-load.d/mbpfan.conf` loads `coretemp`; add `applesmc` there too if
your kernel does not autoload it.

## Build

```sh
make
```

This produces `bin/mbpfan` and `bin/mbpfan-tests`.

## Install

```sh
sudo make install
```

Installs:

- `/usr/sbin/mbpfan`
- `/etc/mbpfan.conf`
- `/etc/init.d/mbpfan` (OpenRC)
- `/etc/modules-load.d/mbpfan.conf`
- `/usr/share/doc/mbpfan/README.md`
- `/usr/share/doc/mbpfan/COPYING`
- `/usr/share/doc/mbpfan/COPYING.LESSER`
- `/usr/share/man/man8/mbpfan.8.gz`

## Run

Foreground:

```sh
sudo mbpfan -f -v
```

As an OpenRC service:

```sh
sudo rc-service mbpfan start
sudo rc-update add mbpfan default
```

## Configuration

Edit `/etc/mbpfan.conf`. See the comments in that file for the temperature
thresholds and fan speed overrides. Send `SIGHUP` to reload the configuration.

## Tests

```sh
sudo make tests
```

The tests read the real `applesmc`/`coretemp` sysfs paths, so they only pass on
supported Mac hardware.

## License

GPL-3.0-or-later. See `COPYING`.

Bundled `settings` and `strmap` code is LGPL-3.0-or-later by Per Ola
Kristensson; see `COPYING.LESSER` and the notices in the source files.

## Credits

Based on:

- [linux-on-mac/mbpfan](https://github.com/linux-on-mac/mbpfan)
- [Allan McRae mbpfan](http://allanmcrae.com/2010/05/simple-macbook-pro-fan-daemon/)
- [rvega/Fan-Control-Daemon](https://github.com/rvega/Fan-Control-Daemon)

Uses Per Ola Kristensson's [ANSI C settings/strmap](http://pokristensson.com/settings.html).

AI use: I use LLMs for code generation and troubleshooting. Usually local Qwen instances or DeepSeek via OpenRouter.

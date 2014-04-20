netchk
======

netchk is a simple network scanner

Usage:
------

netchk [OPTIONS] NETWORK END

<pre>
$ netchk -w 10.10.10.1 5
              IP    ping                               ip-lookup
      10.10.10.1      ok                               fritz.box
      10.10.10.2  failed                                  failed
      10.10.10.3  failed                                  failed
      10.10.10.4      ok                                  failed
      10.10.10.5  failed                                  failed
Finished 5 ips in 2 seconds
</pre>


Installation:
-------------

The simplest way to compile this package is:

1. `cd' to the directory containing the package's source code and type
   `./configure' to check your system for dependencies

2. Type `make' to compile the package.

3. Type `make install' to install the programs and any data files and
   documentation.  When installing into a prefix owned by root, it is
   recommended that the package be configured and built as a regular
   user, and only the `make install' phase executed with root
   privileges.

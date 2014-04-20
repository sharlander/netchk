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

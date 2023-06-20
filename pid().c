#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   int mypid, myppid;
   printf("Program to know PID and PPID's information\n");
   mypid = getpid();
   myppid = getppid();
   printf("My process ID is %d\n", mypid);
   printf("My parent process ID is %d\n", myppid);
   printf("Cross verification of pid's by executing process commands on shell\n");
   system("ps -ef");
   return 0;
}

/*output:
syed@syed-VirtualBox:~/Desktop/linux$ ./pid_test
Program to know PID and PPID's information
My process ID is 144520
My parent process ID is 139938
Cross verification of pid's by executing process commands on shell
UID          PID    PPID  C STIME TTY          TIME CMD
root           1       0  0 Jun18 ?        00:00:33 /sbin/init splash
root           2       0  0 Jun18 ?        00:00:00 [kthreadd]
root           3       2  0 Jun18 ?        00:00:00 [rcu_gp]
root           4       2  0 Jun18 ?        00:00:00 [rcu_par_gp]
root           5       2  0 Jun18 ?        00:00:00 [slub_flushwq]
root           6       2  0 Jun18 ?        00:00:00 [netns]
root           8       2  0 Jun18 ?        00:00:00 [kworker/0:0H-events_highpri]
root          10       2  0 Jun18 ?        00:00:00 [mm_percpu_wq]
root          11       2  0 Jun18 ?        00:00:00 [rcu_tasks_kthread]
root          12       2  0 Jun18 ?        00:00:00 [rcu_tasks_rude_kthread]
root          13       2  0 Jun18 ?        00:00:00 [rcu_tasks_trace_kthread]
root          14       2  0 Jun18 ?        00:00:17 [ksoftirqd/0]
root          15       2  0 Jun18 ?        00:00:57 [rcu_preempt]
root          16       2  0 Jun18 ?        00:00:04 [migration/0]
root          17       2  0 Jun18 ?        00:00:00 [idle_inject/0]
root          19       2  0 Jun18 ?        00:00:00 [cpuhp/0]
root          20       2  0 Jun18 ?        00:00:00 [kdevtmpfs]
root          21       2  0 Jun18 ?        00:00:00 [inet_frag_wq]
root          22       2  0 Jun18 ?        00:00:00 [kauditd]
root          23       2  0 Jun18 ?        00:00:00 [khungtaskd]
root          24       2  0 Jun18 ?        00:00:00 [oom_reaper]
root          27       2  0 Jun18 ?        00:00:00 [writeback]
root          28       2  0 Jun18 ?        00:00:38 [kcompactd0]
root          29       2  0 Jun18 ?        00:00:00 [ksmd]
root          30       2  0 Jun18 ?        00:00:00 [khugepaged]
root          31       2  0 Jun18 ?        00:00:00 [kintegrityd]
root          32       2  0 Jun18 ?        00:00:00 [kblockd]
root          33       2  0 Jun18 ?        00:00:00 [blkcg_punt_bio]
root          34       2  0 Jun18 ?        00:00:00 [tpm_dev_wq]
root          35       2  0 Jun18 ?        00:00:00 [ata_sff]
root          36       2  0 Jun18 ?        00:00:00 [md]
root          37       2  0 Jun18 ?        00:00:00 [edac-poller]
root          38       2  0 Jun18 ?        00:00:00 [devfreq_wq]
root          39       2  0 Jun18 ?        00:00:00 [watchdogd]
root          40       2  0 Jun18 ?        00:00:48 [kworker/0:1H-kblockd]
root          41       2  0 Jun18 ?        00:00:53 [kswapd0]
root          42       2  0 Jun18 ?        00:00:00 [ecryptfs-kthread]
root          48       2  0 Jun18 ?        00:00:00 [kthrotld]
root          52       2  0 Jun18 ?        00:00:00 [acpi_thermal_pm]
root          53       2  0 Jun18 ?        00:00:00 [xenbus_probe]
root          54       2  0 Jun18 ?        00:00:00 [scsi_eh_0]
root          55       2  0 Jun18 ?        00:00:00 [scsi_tmf_0]
root          56       2  0 Jun18 ?        00:00:00 [scsi_eh_1]
root          57       2  0 Jun18 ?        00:00:00 [scsi_tmf_1]
root          58       2  0 Jun18 ?        00:00:00 [vfio-irqfd-clea]
root          60       2  0 Jun18 ?        00:00:00 [mld]
root          61       2  0 Jun18 ?        00:00:00 [ipv6_addrconf]
root          66       2  0 Jun18 ?        00:00:00 [kstrp]
root          72       2  0 Jun18 ?        00:00:00 [zswap-shrink]
root          73       2  0 Jun18 ?        00:00:00 [kworker/u3:0]
root         119       2  0 Jun18 ?        00:00:00 [charger_manager]
root         161       2  0 Jun18 ?        00:00:00 [scsi_eh_2]
root         162       2  0 Jun18 ?        00:00:00 [scsi_tmf_2]
root         188       2  0 Jun18 ?        00:00:14 [jbd2/sda3-8]
root         189       2  0 Jun18 ?        00:00:00 [ext4-rsv-conver]
root         228       1  0 Jun18 ?        00:00:06 /lib/systemd/systemd-journald
root         263       1  0 Jun18 ?        00:00:01 /lib/systemd/systemd-udevd
root         334       2  0 Jun18 ?        00:00:11 [irq/18-vmwgfx]
root         335       2  0 Jun18 ?        00:00:00 [card0-crtc0]
root         336       2  0 Jun18 ?        00:00:00 [card0-crtc1]
root         337       2  0 Jun18 ?        00:00:00 [card0-crtc2]
root         338       2  0 Jun18 ?        00:00:00 [card0-crtc3]
root         339       2  0 Jun18 ?        00:00:00 [card0-crtc4]
root         341       2  0 Jun18 ?        00:00:00 [card0-crtc5]
root         345       2  0 Jun18 ?        00:00:00 [card0-crtc6]
root         346       2  0 Jun18 ?        00:00:00 [card0-crtc7]
root         348       2  0 Jun18 ?        00:00:00 [cryptd]
systemd+     530       1  0 Jun18 ?        00:07:45 /lib/systemd/systemd-oomd
systemd+     531       1  0 Jun18 ?        00:00:35 /lib/systemd/systemd-resolved
systemd+     532       1  0 Jun18 ?        00:00:02 /lib/systemd/systemd-timesyncd
root         647       1  0 Jun18 ?        00:00:06 /usr/libexec/accounts-daemon
root         648       1  0 Jun18 ?        00:00:03 /usr/sbin/acpid
root         651       1  0 Jun18 ?        00:00:00 /usr/sbin/cron -f -P
message+     652       1  0 Jun18 ?        00:00:19 @dbus-daemon --system --address=systemd: --nofork --nopidfile --sy
root         654       1  0 Jun18 ?        00:00:14 /usr/sbin/NetworkManager --no-daemon
root         666       1  0 Jun18 ?        00:00:00 /usr/bin/python3 /usr/bin/networkd-dispatcher --run-startup-trigge
root         667       1  0 Jun18 ?        00:00:06 /usr/libexec/polkitd --no-debug
root         670       1  0 Jun18 ?        00:00:00 /usr/libexec/power-profiles-daemon
syslog       673       1  0 Jun18 ?        00:00:01 /usr/sbin/rsyslogd -n -iNONE
root         679       1  0 Jun18 ?        00:00:00 /usr/libexec/switcheroo-control
root         682       1  0 Jun18 ?        00:00:01 /lib/systemd/systemd-logind
root         683       1  0 Jun18 ?        00:00:01 /usr/libexec/udisks2/udisksd
root         684       1  0 Jun18 ?        00:00:02 /sbin/wpa_supplicant -u -s -O /run/wpa_supplicant
root         732       1  0 Jun18 ?        00:00:00 /usr/sbin/ModemManager
root         754       1  0 Jun18 ?        00:00:00 /usr/bin/python3 /usr/share/unattended-upgrades/unattended-upgrade
root         767       1  0 Jun18 ?        00:00:00 /usr/sbin/gdm3
kernoops     811       1  0 Jun18 ?        00:00:09 /usr/sbin/kerneloops --test
kernoops     821       1  0 Jun18 ?        00:00:09 /usr/sbin/kerneloops
root         827       2  0 Jun18 ?        00:00:00 [iprt-VBoxWQueue]
root         831       2  0 Jun18 ?        00:00:00 [iprt-VBoxTscThread]
rtkit        849       1  0 Jun18 ?        00:00:04 /usr/libexec/rtkit-daemon
root        1025       1  0 Jun18 ?        00:00:07 /usr/libexec/upowerd
root        1059       1  0 Jun18 ?        00:00:02 /usr/libexec/packagekitd
colord      1214       1  0 Jun18 ?        00:00:00 /usr/libexec/colord
root        1324     767  0 Jun18 ?        00:00:00 gdm-session-worker [pam/gdm-password]
syed        1335       1  0 Jun18 ?        00:00:16 /lib/systemd/systemd --user
syed        1337    1335  0 Jun18 ?        00:00:00 (sd-pam)
syed        1343    1335  0 Jun18 ?        00:00:00 /usr/bin/pipewire
syed        1344    1335  0 Jun18 ?        00:00:00 /usr/bin/pipewire-media-session
syed        1345    1335  0 Jun18 ?        00:00:18 /usr/bin/pulseaudio --daemonize=no --log-target=journal
syed        1353    1335  0 Jun18 ?        00:00:18 /usr/bin/dbus-daemon --session --address=systemd: --nofork --nopid
syed        1355       1  0 Jun18 ?        00:00:01 /usr/bin/gnome-keyring-daemon --daemonize --login
syed        1359    1335  0 Jun18 ?        00:00:00 /usr/libexec/gvfsd
syed        1367    1335  0 Jun18 ?        00:00:00 /usr/libexec/gvfsd-fuse /run/user/1000/gvfs -f
syed        1381    1324  0 Jun18 tty2     00:00:00 /usr/libexec/gdm-wayland-session env GNOME_SHELL_SESSION_MODE=ubun
syed        1386    1381  0 Jun18 tty2     00:00:00 /usr/libexec/gnome-session-binary --session=ubuntu
syed        1387    1335  0 Jun18 ?        00:00:00 /usr/libexec/xdg-document-portal
syed        1391    1335  0 Jun18 ?        00:00:00 /usr/libexec/xdg-permission-store
root        1400    1387  0 Jun18 ?        00:00:00 fusermount3 -o rw,nosuid,nodev,fsname=portal,auto_unmount,subtype=
syed        1435    1335  0 Jun18 ?        00:00:21 /usr/libexec/tracker-miner-fs-3
syed        1453    1335  0 Jun18 ?        00:00:00 /usr/libexec/gnome-session-ctl --monitor
syed        1465    1335  0 Jun18 ?        00:00:01 /usr/libexec/gnome-session-binary --systemd-service --session=ubun
syed        1474    1335  0 Jun18 ?        00:00:02 /usr/libexec/gvfs-udisks2-volume-monitor
syed        1485    1335  0 Jun18 ?        00:00:17 /usr/libexec/gvfs-afc-volume-monitor
syed        1493    1335  2 Jun18 ?        00:56:03 /usr/bin/gnome-shell
syed        1494    1465  0 Jun18 ?        00:00:00 /usr/libexec/at-spi-bus-launcher --launch-immediately
syed        1496    1335  0 Jun18 ?        00:00:00 /usr/libexec/gvfs-gphoto2-volume-monitor
syed        1507    1494  0 Jun18 ?        00:00:00 /usr/bin/dbus-daemon --config-file=/usr/share/defaults/at-spi2/acc
syed        1508    1335  0 Jun18 ?        00:00:00 /usr/libexec/gvfs-goa-volume-monitor
syed        1512    1335  0 Jun18 ?        00:00:00 /usr/libexec/goa-daemon
syed        1538    1335  0 Jun18 ?        00:00:01 /usr/libexec/goa-identity-service
syed        1542    1335  0 Jun18 ?        00:00:00 /usr/libexec/gvfs-mtp-volume-monitor
syed        1591    1335  0 Jun18 ?        00:00:01 /usr/libexec/gnome-shell-calendar-server
syed        1597    1335  0 Jun18 ?        00:00:00 /usr/libexec/evolution-source-registry
syed        1605    1335  0 Jun18 ?        00:00:00 /usr/libexec/evolution-calendar-factory
syed        1617    1335  0 Jun18 ?        00:00:00 /usr/libexec/dconf-service
syed        1623    1335  0 Jun18 ?        00:00:00 /usr/libexec/evolution-addressbook-factory
syed        1636    1359  0 Jun18 ?        00:00:00 /usr/libexec/gvfsd-trash --spawner :1.2 /org/gtk/gvfs/exec_spaw/0
syed        1645    1335  0 Jun18 ?        00:00:00 /usr/bin/gjs /usr/share/gnome-shell/org.gnome.Shell.Notifications
syed        1647    1335  0 Jun18 ?        00:00:00 /usr/libexec/at-spi2-registryd --use-gnome-session
syed        1670    1335  0 Jun18 ?        00:00:00 sh -c /usr/bin/ibus-daemon --panel disable $([ "$XDG_SESSION_TYPE"
syed        1673    1670  0 Jun18 ?        00:01:26 /usr/bin/ibus-daemon --panel disable
syed        1674    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-a11y-settings
syed        1679    1335  0 Jun18 ?        00:00:01 /usr/libexec/gsd-color
syed        1680    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-datetime
syed        1681    1335  0 Jun18 ?        00:00:14 /usr/libexec/gsd-housekeeping
syed        1684    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-keyboard
syed        1685    1335  0 Jun18 ?        00:00:01 /usr/libexec/gsd-media-keys
syed        1690    1335  0 Jun18 ?        00:00:02 /usr/libexec/gsd-power
syed        1691    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-print-notifications
syed        1692    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-rfkill
syed        1701    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-screensaver-proxy
syed        1702    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-sharing
syed        1709    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-smartcard
syed        1714    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-sound
syed        1715    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-wacom
syed        1733    1465  0 Jun18 ?        00:00:01 /usr/libexec/evolution-data-server/evolution-alarm-notify
syed        1758    1465  0 Jun18 ?        00:00:00 /usr/libexec/gsd-disk-utility-notify
syed        1784    1673  0 Jun18 ?        00:00:00 /usr/libexec/ibus-dconf
syed        1785    1673  0 Jun18 ?        00:00:11 /usr/libexec/ibus-extension-gtk3
syed        1808    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-printer
syed        1810    1335  0 Jun18 ?        00:00:00 /usr/libexec/ibus-portal
syed        1864    1335  0 Jun18 ?        00:00:10 /usr/libexec/xdg-desktop-portal
syed        1870    1335  0 Jun18 ?        00:00:13 /usr/libexec/xdg-desktop-portal-gnome
syed        1896    1673  0 Jun18 ?        00:00:27 /usr/libexec/ibus-engine-simple
syed        1913    1335  0 Jun18 ?        00:00:01 /usr/libexec/xdg-desktop-portal-gtk
syed        1938    1335  0 Jun18 ?        00:00:00 /usr/bin/gjs /usr/share/gnome-shell/org.gnome.ScreenSaver
syed        1993    1335  0 Jun18 ?        00:00:00 /usr/libexec/gvfsd-metadata
syed        2085    1493  0 Jun18 ?        00:02:06 /usr/bin/Xwayland :0 -rootless -noreset -accessx -core -auth /run/
syed        2088    1335  0 Jun18 ?        00:00:00 /usr/libexec/gsd-xsettings
syed        2124    1335  0 Jun18 ?        00:00:00 /usr/libexec/ibus-x11
syed        2234    1335  0 Jun18 ?        00:00:08 /usr/bin/snap userd
syed        2725    1465  0 Jun18 ?        00:00:11 update-notifier
syed        8767    1359  0 Jun18 ?        00:00:00 /usr/libexec/gvfsd-network --spawner :1.2 /org/gtk/gvfs/exec_spaw/
syed        8783    1359  0 Jun18 ?        00:00:00 /usr/libexec/gvfsd-dnssd --spawner :1.2 /org/gtk/gvfs/exec_spaw/3
syed       48545    1335  0 Jun19 ?        00:01:04 /usr/bin/nautilus --gapplication-service
syed       83949    1335  0 Jun19 ?        00:00:00 /snap/snapd-desktop-integration/83/usr/bin/snapd-desktop-integrati
syed       84136   83949  0 Jun19 ?        00:00:00 /snap/snapd-desktop-integration/83/usr/bin/snapd-desktop-integrati
avahi      92307       1  0 00:46 ?        00:00:00 avahi-daemon: running [syed-VirtualBox.local]
avahi      92308   92307  0 00:46 ?        00:00:00 avahi-daemon: chroot helper
syed       95662    1493  0 00:52 ?        00:05:34 /snap/firefox/2760/usr/lib/firefox/firefox
syed       96299   95662  0 00:53 ?        00:00:00 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -parentBui
syed       96377   95662  0 00:53 ?        00:00:01 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -childID 1
syed       96409   95662  0 00:53 ?        00:00:05 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -childID 2
syed       96459   95662  0 00:53 ?        00:04:34 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -childID 4
syed       97552   95662  0 00:54 ?        00:00:00 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -parentBui
syed       97555   95662  0 00:54 ?        00:00:00 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -parentBui
root      120230       1  0 01:07 ?        00:00:19 /usr/lib/snapd/snapd
root      137753       1  0 03:28 ?        00:00:00 /usr/sbin/cupsd -l
root      137790       1  0 03:28 ?        00:00:00 /usr/sbin/cups-browsed
syed      139911    1335  0 04:05 ?        00:00:30 /usr/libexec/gnome-terminal-server
syed      139938  139911  0 04:05 pts/1    00:00:00 bash
syed      140736    1335  0 05:45 ?        00:00:43 /usr/bin/gedit --gapplication-service
root      142476       1  0 08:42 ?        00:00:03 /usr/libexec/fwupd/fwupd
syed      142887    1493  0 08:55 ?        00:00:03 rhythmbox
root      143811       2  0 10:13 ?        00:00:00 [kworker/u2:0-events_unbound]
root      144079       2  0 10:28 ?        00:00:00 [kworker/u2:2-events_unbound]
root      144118       2  0 10:30 ?        00:00:01 [kworker/0:2-events]
root      144163       2  0 10:37 ?        00:00:00 [kworker/0:1-events]
root      144277       2  0 10:37 ?        00:00:00 [kworker/u2:3-events_power_efficient]
syed      144279    1493  0 10:37 ?        00:00:01 gjs /usr/share/gnome-shell/extensions/ding@rastersoft.com/ding.js 
syed      144328   95662  0 10:37 ?        00:00:00 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -childID 6
syed      144405   95662  0 10:39 ?        00:00:00 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -childID 6
syed      144444   95662  0 10:39 ?        00:00:00 /snap/firefox/2760/usr/lib/firefox/firefox -contentproc -childID 6
root      144509       2  0 10:44 ?        00:00:00 [kworker/u2:1]
syed      144515    1335  1 10:44 ?        00:00:00 /usr/libexec/tracker-extract-3
syed      144520  139938  0 10:44 pts/1    00:00:00 ./pid_test
syed      144521  144520  0 10:44 pts/1    00:00:00 sh -c ps -ef
syed      144522  144521  0 10:44 pts/1    00:00:00 ps -ef
syed@syed-VirtualBox:~/Desktop/linux$
*/
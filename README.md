# G-Sync-Windowed-Fix
A fix for G-Sync limiting itself to ~23 fps when you first start your computer.

This fix works by changing the screen from windowed to fullscreen and back at startup. This seems to trigger the Nvidia drivers to fix itself.

To install run "shell:startup" with WIN+R keys.
Put the "G-SyncFix.exe" in the folder that pops up.

If you do not trust the exe I supplied you can compile it yourself with Visual Studio.
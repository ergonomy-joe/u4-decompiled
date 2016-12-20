Low-level functions are implemented in 3 differents files: CGA.DRV, EGA.DRV, TANDY.DRV.
At runtime, only one is loaded in memory and its functions addressed through some "hooks" placed at the beginning at the file.
Only AVATAR.EXE uses this system. TITLE.EXE has the functions for all three types of devices linked into it.
Since this is not the most interesting part of the job (and since I love CGA), I only reversed CGA.DRV.

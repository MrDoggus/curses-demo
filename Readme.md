## Hello...

I am trying to learn ncurses/pdcurses for my [btetris](https://github.com/MrDoggus/BTetris) demo. 
I am walking through [this youtube playlist](https://www.youtube.com/watch?v=lV-OPQhPvSM&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&pp=iAQB) to learn. 

## Files
 - main0: Hello World
 - main1: Moving cursors
 - main2: basics of windows
 - main3: borders and environment options
 - main3cp: debuging windows terminal issue
 - main4: attributes and colors
 - main5: getting info from the terminal

## Notes
 - windows terminal console text is skewed.
   - Want to assume pdcurse's console size is inaccurate initially because windows does funky stuff 
   - When running main3.exe from window's file explore, for example, the windows terminal display of the window box is screwed up.
   - This doesnt happen when running ncurses in WSL, running the .exe in WSL, or running the .exe with the windows console host. 
   - use `resize_term(0, 0)` to update it correctly. 
   - There has to be enough of a delay before calling `resize_term` otherwise it wont fix the issue. 
   - This issue doesnt happen for the examples given with the pdcurses repo. 
   - Maybe im doing something wrong?
 - `init_color()` doesnt work on the windows terminal, similar to the note above. 

import win32gui
import win32api
import os
import spotify_exceptions as se

###Virtual-KeyCodes###
Media_Next = 0xB0
Media_Previous = 0xB1
Media_Pause = 0xB3 ##Play/Pause
Media_Mute = 0xAD



###SpotifyInfo###
def find_spotify_uwp(hwnd, windows):
        text = win32gui.GetWindowText(hwnd)
        classname = win32gui.GetClassName(hwnd)
        if classname == "Chrome_WidgetWin_0" and len(text) > 0:
            windows.append(text)
            

def getwindow():
    windows = []
    win32gui.EnumWindows(find_spotify_uwp, windows)
    if len(windows) == 0:
        raise se.NoSpotifyError("No Spotify window found")
    return windows	
	
def song_info():
    try:
        windows = getwindow()
        artist, track = windows[0].split(" - ", 1)
        return artist, track
    except se.NoSpotifyError:
        return "No Spotify window found", "None"
        
		

def artist():
    artist, song = song_info()
    artist = artist.strip()
    return artist if artist != "No Spotify window found" else "Nothing is playing"
    

	
	
def song():
    artist, song = song_info()
    song = song.strip()
    return song if song != "None" else "Nothing is playing"
    


###Media Controls###
def hwcode(media):
	hwcode = win32api.MapVirtualKey(media, 0)
	return hwcode

def next():
	win32api.keybd_event(Media_Next, hwcode(Media_Next))
	
def previous():
	win32api.keybd_event(Media_Previous, hwcode(Media_Previous))
	
def pause():
	win32api.keybd_event(Media_Pause, hwcode(Media_Pause))
	
def play():
	win32api.keybd_event(Media_Pause, hwcode(Media_Pause))
	
def mute():
	win32api.keybd_event(Media_Mute, hwcode(Media_Mute))
	
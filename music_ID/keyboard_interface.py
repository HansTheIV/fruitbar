import hid
import spotilib as sp
# Dependencies include:
# hid
# hidapi

KEYBOARD_NAME = "fruitbar"
VENDOR_ID  = 0x666B
PRODUCT_ID = 0x6662
USAGE_PAGE = 0xFF60
USAGE_ID   = 0X61

async def send_string(string:str) -> bool:
    return True

async def get_string() -> str:
    return ""


async def main() -> None:
    with hid.Device(vid=VENDOR_ID, pid=PRODUCT_ID) as h:
        print(sp.song())
    
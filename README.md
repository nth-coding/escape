# Escape

# Giới thiệu
  #### `Escape` là một tựa game được làm bằng SFML (Simple and Fast Multimedia Library). Trong đó, SFML được sử dụng để vẽ các đối tượng trên màn hình mỗi frame. `Escape` là 1 game RPG đơn giản theo mô tuýp đánh quái vật, tăng level. Ở đây, nhiệm vụ của người chơi là đánh quái vật và sống sót thoát ra khỏi mê cung!
  
# Cách vào và cài đặt game
  - Bước 1: Cài đặt cho máy của bạn [mingw32 (hoặc mingw64)](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-win32/seh/x86_64-7.3.0-release-win32-seh-rt_v5-rev0.7z/download)
  - Bước 2: Đặt path trong system environment variables
  - Bước 3: Clone game về bằng lệnh git clone hoặc tải về [tại đây](https://github.com/nth-coding/escape/archive/refs/heads/main.zip)
  - Bước 4: Hãy để vị trí của game tại ngoài ổ \C: máy tính của bạn
  - Bước 5: Mở thư mục `build` và click vào `game.exe` hoặc `build.sh` để bắt đầu chơi game nàooo!

*Còn nếu muốn bật hitbox thì hãy chạy `build_with_hitbox.sh` trong `build`*

# Chi tiết về game:

## Gameplay 

**- Xem qua video gameplay tại đây: https://youtu.be/0f7jj8l0zjQ**

**Control (Keybind)**
  - `W`: Đi lên
  - `A`: Đi sang trái
  - `S`: Đi xuống
  - `D`: Đi sang phải

  - `Left-mouse`: Tấn công
  
  *.. Tăng thêm độ khó trong combat: Để tấn công được quái thì ta còn cần click chuột đúng vào trong vùng hitbox của quái để gây dmg cho quái ..*

### Các nhân vật trong game

**Player**

![player_sheet](https://github.com/nth-coding/escape/blob/main/build/textures/player.png)

**Enermies**

- Mỗi loại quái đều có những chỉ số và các đặc điểm khác nhau, đặc trưng cho từng loại... Khám phá thêm trong gameplay.
- Đây là hình ảnh minh họa của 4 loại quái đến hiện tại:

  - Charger:
![chort_idle_anim_f0](https://user-images.githubusercontent.com/93527021/170883286-b241fe8a-b57e-4159-9e45-9c34c719ba97.png)

  - Demon:
![big_demon_idle_anim_f0](https://user-images.githubusercontent.com/93527021/170883270-25631dd5-8aa7-4a2e-bbe3-8f0a2af9e5aa.png)

  - Muddy:
![swampy_idle_anim_f2](https://user-images.githubusercontent.com/93527021/170861951-29b7a727-fa97-4774-a293-4513b084987d.png)

  - Ogre (Boss):
![ogre_idle_anim_f0](https://user-images.githubusercontent.com/93527021/170861974-393a1c11-789d-4b6b-b2d4-67e00c4dfba9.png)

*.. Will update more ..*

### Vũ khí và items khác
  - Vũ khí đầu là dao phay ![](https://user-images.githubusercontent.com/93527021/170829350-f936e157-5e2e-4ea6-a70b-3d81290a1734.png).
  - Mỗi vũ khí đều có **level**, **damage min/max**, **range**. 

  **Items**
  
  - Đặt bằng cách vào map_editor, chuyển sang loại enemy_editor và chọn type.
  - Chest: [type = 4]
![chest_empty_open_anim_f0](https://user-images.githubusercontent.com/93527021/173222771-b7088a43-56ed-40ff-a4ba-8f2a359952ad.png)
  

  *..Sẽ cố update các loại items như potions, atk_buff, def_buff,..vân vân..mây mây..*

### Power up! hay Level up!
  - Nhân vật sẽ có một thanh kinh nghiệm.
  - Mỗi khi thanh kinh nghiệm đầy thì các chỉ số sẽ được cập nhật lại và mạnh hơn trước và máu sẽ đc reset.

### Battle ⚔
  - Tìm đường thoát và tiêu diệt quái vật, quan trọng hơn là **sống sót**
  - Giết quái vật sẽ cho bạn kinh nghiệm *và có thể tiền hoặc điểm (sẽ cố update trong tương lai)* 
  - Giết boss và thoát khỏi mê cung
  

## Các tính năng của game:

### Setting
  - Có thể thay đổi size của window theo các thông số có trước
  - Ấn vào `Apply` để kích hoạt thông số đã chọn
  - Ấn vào `Quit` để out ra menu

### Map Editor 
  Là một công cụ để vẽ map, điều chỉnh các hình ảnh, collision, sinh quái vật...
 
**Control (Keybind)**:
  - `W`: Di chuyển camera lên phía trên
  - `A`: Di chuyển camera về phía trái
  - `S`: Di chuyển camera xuống phía dưới
  - `D`: Di chuyển camera về phía bên phải

  - `Page_Up` & `Page_Down`: chuyển sang chế độ khác

 Khi ở chế độ điều chỉnh TileMap:
  - `Left-mouse` (chuột trái): Thêm tile ở vị trí con trỏ chuột
  - `Right-mouse` (chuột phải): Xóa tile ở vị trí con trỏ chuột
  - `C`: chuyển tile sang chế độ cản trở (không thể đi qua) (Toggle collision)
  - `L`: chuyển tile sang chế độ khóa (Toggle tile lock)
  
 Khi sang chế độ điều chỉnh sinh quái:
  - `Num1` & `Shift + Num1`: Chuyển loại quái (Ví dụ: Enemy Type: 1 -> Enemy Type: 2 và ngược lại) 
  
  *.. Hiện tại mới có 4 thể loại quái nên vui lòng chỉ dùng từ 0 -> 3 ..*
  
  - `Num2` & `Shift + Num2`: Tăng giảm số lượng sinh quái 
  - `Num3` & `Shift + Num3`: Tăng giảm thời gian sinh quái
  - `Num4` & `Shift + Num4`: Tăng giảm `Max distance`
  

**Collision Box**
  - Để bật/tắt collision box, ta ấn vào nút `TS` ở góc trên trái của màn hình
  - Hãy ấn và chọn Tile theo mong muốn của bạn

**Pause Menu**
  - Để kích hoạt ấn nút Esc
  - Pause Menu có tác dụng trong gameplay và map editor
 
  - Ở MapEditor, Pause menu sẽ có:
    - `Continue`: Tiếp tục game (Unpause)
    - `Sound: ON/OFF`: Tắt tiếng nhạc nền
    - `Load`: Tải map được lưu gần đây nhất
    - `Save`: Lưu map vừa tạo (sau khi click save sẽ tự out ra menu)
    - `Quit`: Thoát ra menu
  
  - Ở Gameplay, Pause menu sẽ có:
    - `Continue`: Tiếp tục game (Unpause)
    - `Sound: ON/OFF`: Tắt tiếng nhạc nền
    - `Quit`: Thoát ra menu

# Kết luận

## Các kĩ thuật dùng trong làm game
 - Các kĩ thuật cơ bản: mảng, hàm, con trỏ, struct, class,...
 - Ngoài ra, sử dụng các kiểu dữ liệu như map, vector, stack,... 
 - Tạo ra AI có chức năng tấn công và tìm đường đi ngắn nhất đến player.
 - Nâng cao: sử dụng tối đa thư viện đồ họa SFML, lập trình hướng đối tượng (OOP), module hóa code, Clean Code...



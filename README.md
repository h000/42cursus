# cub3d
- map 파일을 파싱해서 Raycasting을 이용해 3D 맵 구현 (minilibX 라이브러리 사용)

- map 파일 예시 (map_basic.cub)<br>
  - 각각 해상도, 북/남/서/동쪽 벽면 이미지 파일, sprite 이미지 파일, 바닥/천장 색<br>
  - 맵에서 1은 벽 0은 빈 공간, 2는 sprite<br>
  - 초기 위치는 N,S,E,W 로 표시 (각각 바라보는 방향)

```
R  640 480
NO ./img/wood.xpm
SO ./img/redbrick.xpm
WE ./img/eagle.xpm
EA ./img/colorstone.xpm
S ./img/barrel.xpm
F 112,128,144
C 169,169,169
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000002000001
        100100N000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
110000011101010111110111100111
11110111 1110101 101111010001
11111111 1111111 111111111111
```



- [MiniLibX Docs](https://harm-smits.github.io/42docs/libs/minilibx) (42 graphic library) <br>

- 레이 캐스팅 Raycasting<br>
  - 2D map에서 3D 관점을 만들기 위해 렌더링하는 기술
  - [참고자료](https://lodev.org/cgtutor/raycasting.html)
  - [Wolfenstein 3D](http://users.atw.hu/wolf3d/)

# NetUser
使用windows api添加用户，可用于net无法使用时

原理：使用NetUserAdd这个API添加普通权限的用户，NetLocalGroupAddMembers这个API添加管理员权限。

需要administrator权限

- NetUser.cpp：普通C++版本
- NetUser.nim：普通Nim版本
- rdi_net_user.cpp：反射型dll注入版本
- bof_net_user.c：CobaltStrike Bof版本
- SamAdduser.exe：利用sam来添加用户，用户名：Admina 密码：Admin&A*125#（暂时有些问题，回头更改）
- NoApiUser.exe：利用windows 目录添加用户，C#版本，并移除了用户名密码字符

效果图：

![00.png](http://ww1.sinaimg.cn/large/007F8GgBly1gaqeeosxcsj30no0ap0sm.jpg)

![01.png](http://ww1.sinaimg.cn/large/007F8GgBly1gaqef13ac8j30pq0fp3yu.jpg)

![02.png](https://raw.githubusercontent.com/lengjibo/NetUser/master/2.png)



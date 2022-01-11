#ifndef HLS_GETLASTERROR_STRING_H
#define HLS_GETLASTERROR_STRING_H

//#include <winerr.h>
#include <errhandlingapi.h>
#include "common/string.h"
#include "string_operate/turn/turn_string_windows.h"

inline string GetLastError_string()
{
	return turn_string(GetLastError());
}

inline string GetLastError_string_meaning()
{
	DWORD error=GetLastError();
	if(error==0)
		return "操作成功完成。";
	if(error==1)
		return "功能错误。";
	if(error==2)
		return "系统找不到指定的文件。";
	if(error==3)
		return "系统找不到指定的路径。";
	if(error==4)
		return "系统无法打开文件。";
	if(error==5)
		return "拒绝访问。";
	if(error==6)
		return "句柄无效。";
	if(error==7)
		return "存储控制块被损坏。";
	if(error==8)
		return "存储空间不足，无法处理此命令。";
	if(error==9)
		return "存储控制块地址无效。";
	if(error==10)
		return "环境错误。";
	if(error==11)
		return "试图加载格式错误的程序。";
	if(error==12)
		return "访问码无效。";
	if(error==13)
		return "数据无效。";
	if(error==14)
		return "存储器不足，无法完成此操作。";
	if(error==15)
		return "系统找不到指定的驱动器。";
	if(error==16)
		return "无法删除目录。";
	if(error==17)
		return "系统无法将文件移到不同的驱动器。";
	if(error==18)
		return "没有更多文件。";
	if(error==19)
		return "介质受写入保护。";
	if(error==20)
		return "系统找不到指定的设备。";
	if(error==21)
		return "设备未就绪。";
	if(error==22)
		return "设备不识别此命令。";
	if(error==23)
		return "数据错误 (循环冗余检查)。";
	if(error==24)
		return "程序发出命令，但命令长度不正确。";
	if(error==25)
		return "驱动器无法找出磁盘上特定区域或磁道的位置。";
	if(error==26)
		return "无法访问指定的磁盘或软盘。";
	if(error==27)
		return "驱动器找不到请求的扇区。";
	if(error==28)
		return "打印机缺纸。";
	if(error==29)
		return "系统无法写入指定的设备。";
	if(error==30)
		return "系统无法从指定的设备上读取。";
	if(error==31)
		return "连到系统上的设备没有发挥作用。";
	if(error==32)
		return "进程无法访问文件，因为另一个程序正在使用此文件。";
	if(error==33)
		return "进程无法访问文件，因为另一个程序已锁定文件的一部分。";
	if(error==36)
		return "用来共享的打开文件过多。";
	if(error==38)
		return "到达文件结尾。";
	if(error==39)
		return "磁盘已满。";
	if(error==50)
		return "不支持网络请求。";
	if(error==51)
		return "远程计算机不可用 。";
	if(error==52)
		return "在网络上已有重复的名称。";
	if(error==53)
		return "找不到网络路径。";
	if(error==54)
		return "网络忙。";
	if(error==55)
		return "指定的网络资源或设备不再可用。";
	if(error==56)
		return "已到达网络 BIOS 命令限制。";
	if(error==57)
		return "网络适配器硬件出错。";
	if(error==58)
		return "指定的服务器无法运行请求的操作。";
	if(error==59)
		return "发生意外的网络错误。";
	if(error==60)
		return "远程适配器不兼容。";
	if(error==61)
		return "打印机队列已满。";
	if(error==62)
		return "无法在服务器上获得用于保存待打印文件的空间。";
	if(error==63)
		return "删除等候打印的文件。";
	if(error==64)
		return "指定的网络名不再可用。";
	if(error==65)
		return "拒绝网络访问。";
	if(error==66)
		return "网络资源类型错误。";
	if(error==67)
		return "找不到网络名。";
	if(error==68)
		return "超过本地计算机网卡的名称限制。";
	if(error==69)
		return "超出网络 BIOS 会话限制。";
	if(error==70)
		return "远程服务器已暂停，或正在启动过程中。";
	if(error==71)
		return "当前已无法再同此远程计算机连接，因为已达到计算机的连接数目极限。";
	if(error==72)
		return "已暂停指定的打印机或磁盘设备。";
	if(error==80)
		return "文件存在。";
	if(error==82)
		return "无法创建目录或文件。";
	if(error==83)
		return "INT 24 失败。";
	if(error==84)
		return "无法取得处理此请求的存储空间。";
	if(error==85)
		return "本地设备名已在使用中。";
	if(error==86)
		return "指定的网络密码错误。";
	if(error==87)
		return "参数错误。";
	if(error==88)
		return "网络上发生写入错误。";
	if(error==89)
		return "系统无法在此时启动另一个进程。";
	if(error==100)
		return "无法创建另一个系统信号灯。";
	if(error==101)
		return "另一个进程拥有独占的信号灯。";
	if(error==102)
		return "已设置信号灯且无法关闭。";
	if(error==103)
		return "无法再设置信号灯。";
	if(error==104)
		return "无法在中断时请求独占的信号灯。";
	if(error==105)
		return "此信号灯的前一个所有权已结束。";
	if(error==107)
		return "程序停止，因为替代的软盘未插入。";
	if(error==108)
		return "磁盘在使用中，或被另一个进程锁定。";
	if(error==109)
		return "管道已结束。";
	if(error==110)
		return "系统无法打开指定的设备或文件。";
	if(error==111)
		return "文件名太长。";
	if(error==112)
		return "磁盘空间不足。";
	if(error==113)
		return "无法再获得内部文件的标识。";
	if(error==114)
		return "目标内部文件的标识不正确。";
	if(error==117)
		return "应用程序制作的 IOCTL 调用错误。";
	if(error==118)
		return "验证写入的切换参数值错误。";
	if(error==119)
		return "系统不支持请求的命令。";
	if(error==120)
		return "此功能只被此系统支持。";
	if(error==121)
		return "信号灯超时时间已到。";
	if(error==122)
		return "传递到系统调用的数据区太小。";
	if(error==123)
		return "文件名、目录名或卷标语法不正确。";
	if(error==124)
		return "系统调用级别错误。";
	if(error==125)
		return "磁盘没有卷标。";
	if(error==126)
		return "找不到指定的模块。";
	if(error==127)
		return "找不到指定的程序。";
	if(error==128)
		return "没有等候的子进程。";
	if(error==130)
		return "试图使用操作(而非原始磁盘 I/O)的已打开磁盘分区的文件句柄。";
	if(error==131)
		return "试图移动文件指针到文件开头之前。";
	if(error==132)
		return "无法在指定的设备或文件上设置文件指针。";
	if(error==133)
		return "包含先前加入驱动器的驱动器无法使用 JOIN 或 SUBST 命令。";
	if(error==134)
		return "试图在已被合并的驱动器上使用 JOIN 或 SUBST 命令。";
	if(error==135)
		return "试图在已被合并的驱动器上使用 JOIN 或 SUBST 命令。";
	if(error==136)
		return "系统试图解除未合并驱动器的 JOIN。";
	if(error==137)
		return "系统试图解除未替代驱动器的 SUBST。";
	if(error==138)
		return "系统试图将驱动器合并到合并驱动器上的目录。";
	if(error==139)
		return "系统试图将驱动器替代为替代驱动器上的目录。";
	if(error==140)
		return "系统试图将驱动器合并到替代驱动器上的目录。";
	if(error==141)
		return "系统试图替代驱动器为合并驱动器上的目录。";
	if(error==142)
		return "系统无法在此时运行 JOIN 或 SUBST。";
	if(error==143)
		return "系统无法将驱动器合并到或替代为相同驱动器上的目录。";
	if(error==144)
		return "目录并非根目录下的子目录。";
	if(error==145)
		return "目录非空。";
	if(error==146)
		return "指定的路径已在替代中使用。";
	if(error==147)
		return "资源不足，无法处理此命令。";
	if(error==148)
		return "指定的路径无法在此时使用。";
	if(error==149)
		return "企图将驱动器合并或替代为驱动器上目录是上一个替代的目标的驱动器。";
	if(error==150)
		return "系统跟踪信息未在 CONFIG.SYS 文件中指定，或不允许跟踪。";
	if(error==151)
		return "为 DosMuxSemWait 指定的信号灯事件个数错误。";
	if(error==152)
		return "DosMuxSemWait 不可运行。已设置过多的信号灯。";
	if(error==153)
		return "DosMuxSemWait 清单错误。";
	if(error==154)
		return "输入的卷标超过目标文件系统的长度限制";
	if(error==155)
		return "无法创建另一个线程。";
	if(error==156)
		return "接收进程已拒绝此信号。";
	if(error==157)
		return "段已被放弃且无法锁定。";
	if(error==158)
		return "段已解除锁定。";
	if(error==159)
		return "线程标识的地址错误。";
	if(error==160)
		return "传递到 DosExecPgm 的参数字符串错误。";
	if(error==161)
		return "指定的路径无效。";
	if(error==162)
		return "信号已暂停。";
	if(error==164)
		return "无法在系统中创建更多的线程。";
	if(error==167)
		return "无法锁定文件区域。";
	if(error==170)
		return "请求的资源在使用中。";
	if(error==173)
		return "对于提供取消区域进行锁定的请求不明显。";
	if(error==174)
		return "文件系统不支持锁定类型的最小单元更改。";
	if(error==180)
		return "系统检测出错误的段号。";
	if(error==183)
		return "当文件已存在时，无法创建该文件。";
	if(error==186)
		return "传递的标志错误。";
	if(error==187)
		return "找不到指定的系统信号灯名称。";
	if(error==196)
		return "操作系统无法运行此应用程序。";
	if(error==197)
		return "操作系统当前的配置不能运行此应用程序。";
	if(error==199)
		return "操作系统无法运行此应用程序。";
	if(error==200)
		return "代码段不可大于或等于 64K。";
	if(error==203)
		return "操作系统找不到已输入的环境选项。";
	if(error==205)
		return "命令子树中的进程没有信号处理程序。";
	if(error==206)
		return "文件名或扩展名太长。";
	if(error==207)
		return "第 2 环堆栈已被占用。";
	if(error==208)
		return "没有正确输入文件名通配符 * 或 ?，或指定过多的文件名通配符。";
	if(error==209)
		return "正在发送的信号错误。";
	if(error==210)
		return "无法设置信号处理程序。";
	if(error==212)
		return "段已锁定且无法重新分配。";
	if(error==214)
		return "连到该程序或动态链接模块的动态链接模块太多。";
	if(error==215)
		return "无法嵌套调用 LoadModule。";
	if(error==230)
		return "管道状态无效。";
	if(error==231)
		return "所有的管道实例都在使用中。";
	if(error==232)
		return "管道正在关闭中。";
	if(error==233)
		return "管道的另一端上无任何进程。";
	if(error==234)
		return "更多数据可用。";
	if(error==240)
		return "取消会话。";
	if(error==254)
		return "指定的扩展属性名无效。";
	if(error==255)
		return "扩展属性不一致。";
	if(error==258)
		return "等待的操作过时。";
	if(error==259)
		return "没有可用的数据了。";
	if(error==266)
		return "无法使用复制功能。";
	if(error==267)
		return "目录名无效。";
	if(error==275)
		return "扩展属性在缓冲区中不适用。";
	if(error==276)
		return "装在文件系统上的扩展属性文件已损坏。";
	if(error==277)
		return "扩展属性表格文件已满。";
	if(error==278)
		return "指定的扩展属性句柄无效。";
	if(error==282)
		return "装入的文件系统不支持扩展属性。";
	if(error==288)
		return "企图释放并非呼叫方所拥有的多用户终端运行程序。";
	if(error==298)
		return "发向信号灯的请求过多。";
	if(error==299)
		return "仅完成部分的 ReadProcessMemoty 或 WriteProcessMemory 请求。";
	if(error==300)
		return "操作锁定请求被拒绝。";
	if(error==301)
		return "系统接收了一个无效的操作锁定确认。";
	if(error==487)
		return "试图访问无效的地址。";
	if(error==534)
		return "算术结果超过 32 位。";
	if(error==535)
		return "管道的另一端有一进程。";
	if(error==536)
		return "等候打开管道另一端的进程。";
	if(error==994)
		return "拒绝访问扩展属性。";
	if(error==995)
		return "由于线程退出或应用程序请求，已放弃 I/O 操作。";
	if(error==996)
		return "重叠 I/O 事件不在信号状态中。";
	if(error==997)
		return "重叠 I/O 操作在进行中。";
	if(error==998)
		return "内存分配访问无效。";
	if(error==999)
		return "错误运行页内操作。";
	if(error==1001)
		return "递归太深；栈溢出。";
	if(error==1002)
		return "窗口无法在已发送的消息上操作。";
	if(error==1003)
		return "无法完成此功能。";
	if(error==1004)
		return "无效标志。";
	if(error==1005)
		return "此卷不包含可识别的文件系统。请确定所有请求的文件系统驱动程序已加载，且此卷未损坏。";
	if(error==1006)
		return "文件所在的卷已被外部改变，因此打开的文件不再有效。";
	if(error==1007)
		return "无法在全屏幕模式下运行请求的操作。";
	if(error==1008)
		return "试图引用不存在的令牌。";
	if(error==1009)
		return "配置注册表数据库损坏。";
	if(error==1010)
		return "配置注册表项无效。";
	if(error==1011)
		return "无法打开配置注册表项。";
	if(error==1012)
		return "无法读取配置注册表项。";
	if(error==1013)
		return "无法写入配置注册表项。";
	if(error==1014)
		return "注册表数据库中的某一文件必须使用记录或替代复制来恢复。恢复成功完成。";
	if(error==1015)
		return "注册表损坏。包含注册表数据的某一文件结构损坏，或系统的文件内存映像损坏，或因为替代副本、日志缺少或损坏而无法恢复文件。";
	if(error==1016)
		return "由注册表启动的 I/O 操作恢复失败。注册表无法读入、写出或清除任意一个包含注册表系统映像的文件。";
	if(error==1017)
		return "系统试图加载或还原文件到注册表，但指定的文件并非注册表文件格式。";
	if(error==1018)
		return "试图在标记为删除的注册表项上运行不合法的操作。";
	if(error==1019)
		return "系统无法配置注册表日志中所请求的空间。";
	if(error==1020)
		return "无法在已有子项或值的注册表项中创建符号链接。";
	if(error==1021)
		return "无法在易变父项下创建稳定子项。";
	if(error==1022)
		return "通知更改请求正在完成中，且信息并未返回到呼叫方的缓冲区中。当前呼叫方必须枚举文件来查找更改。";
	if(error==1051)
		return "已发送停止控制到服务，该服务被其它正在运行的服务所依赖。";
	if(error==1052)
		return "请求的控件对此服务无效";
	if(error==1053)
		return "服务并未及时响应启动或控制请求。";
	if(error==1054)
		return "无法创建此服务的线程。";
	if(error==1055)
		return "锁定服务数据库。";
	if(error==1056)
		return "服务的实例已在运行中。";
	if(error==1057)
		return "帐户名无效或不存在，或者密码对于指定的帐户名无效。";
	if(error==1058)
		return "无法启动服务，原因可能是它被禁用或与它相关联的设备没有启动。";
	if(error==1059)
		return "指定了循环服务依存。";
	if(error==1060)
		return "指定的服务并未以已安装的服务存在。";
	if(error==1061)
		return "服务无法在此时接受控制信息。";
	if(error==1062)
		return "服务未启动。";
	if(error==1063)
		return "服务进程无法连接到服务控制器上。";
	if(error==1064)
		return "当处理控制请求时，在服务中发生异常。";
	if(error==1065)
		return "指定的数据库不存在。";
	if(error==1066)
		return "服务已返回特定的服务错误码。";
	if(error==1067)
		return "进程意外终止。";
	if(error==1068)
		return "依存服务或组无法启动。";
	if(error==1069)
		return "由于登录失败而无法启动服务。";
	if(error==1070)
		return "启动后，服务停留在启动暂停状态。";
	if(error==1071)
		return "指定的服务数据库锁定无效。";
	if(error==1072)
		return "指定的服务已标记为删除。";
	if(error==1073)
		return "指定的服务已存在。";
	if(error==1074)
		return "系统当前以最新的有效配置运行。";
	if(error==1075)
		return "依存服务不存在，或已被标记为删除。";
	if(error==1076)
		return "已接受使用当前引导作为最后的有效控制设置。";
	if(error==1077)
		return "上次启动之后，仍未尝试引导服务。";
	if(error==1078)
		return "名称已用作服务名或服务显示名。";
	if(error==1079)
		return "此服务的帐户不同于运行于同一进程上的其它服务的帐户。";
	if(error==1080)
		return "只能为 Win32 服务设置失败操作，不能为驱动程序设置。";
	if(error==1081)
		return "这个服务所运行的处理和服务控制管理器相同。所以，如果服务处理程序意外中止的话，服务控制管理器无法进行任何操作。";
	if(error==1082)
		return "这个服务尚未设置恢复程序。";
	if(error==1083)
		return "配置成在该可执行程序中运行的这个服务不能执行该服务。";
	if(error==1100)
		return "已达磁带的实际结尾。";
	if(error==1101)
		return "磁带访问已达文件标记。";
	if(error==1102)
		return "已达磁带或磁盘分区的开头。";
	if(error==1103)
		return "磁带访问已达一组文件的结尾。";
	if(error==1104)
		return "磁带上不再有任何数据。";
	if(error==1105)
		return "磁带无法分区。";
	if(error==1106)
		return "在访问多卷分区的新磁带时，当前的块大小不正确。";
	if(error==1107)
		return "当加载磁带时，找不到分区信息。";
	if(error==1108)
		return "无法锁定媒体弹出功能。";
	if(error==1109)
		return "无法卸载介质。";
	if(error==1110)
		return "驱动器中的介质可能已更改。";
	if(error==1111)
		return "复位 I/O 总线。";
	if(error==1112)
		return "驱动器中没有媒体。";
	if(error==1113)
		return "在多字节的目标代码页中，没有此 Unicode 字符可以映射到的字符。";
	if(error==1114)
		return "动态链接库 (DLL) 初始化例程失败。";
	if(error==1115)
		return "系统关机正在进行。";
	if(error==1116)
		return "因为没有任何进行中的关机过程，所以无法中断系统关机。";
	if(error==1117)
		return "因为 I/O 设备错误，所以无法运行此项请求。";
	if(error==1118)
		return "没有串行设备被初始化成功。串行驱动程序将卸载。";
	if(error==1119)
		return "无法打开正在与其他设备共享中断请求(IRQ)的设备。至少有一个使用该 IRQ 的其他设备已打开。";
	if(error==1120)
		return "序列 I/O 操作已由另一个串行口的写入完成。(IOCTL_SERIAL_XOFF_COUNTER 已达零。)";
	if(error==1121)
		return "因为已过超时时间，所以串行 I/O 操作完成。(IOCTL_SERIAL_XOFF_COUNTER 未达零。)";
	if(error==1122)
		return "在软盘上找不到 ID 地址标记。";
	if(error==1123)
		return "软盘扇区 ID 字符域与软盘控制器磁道地址不相符。";
	if(error==1124)
		return "软盘控制器报告软盘驱动程序不能识别的错误。";
	if(error==1125)
		return "软盘控制器返回与其寄存器中不一致的结果。";
	if(error==1126)
		return "当访问硬盘时，重新校准操作失败，重试仍然失败。";
	if(error==1127)
		return "当访问硬盘时，磁盘操作失败，重试仍然失败。";
	if(error==1128)
		return "当访问硬盘时，即使失败，仍须复位磁盘控制器。";
	if(error==1129)
		return "已达磁带结尾。";
	if(error==1130)
		return "服务器存储空间不足，无法处理此命令。";
	if(error==1131)
		return "检测出潜在的死锁状态。";
	if(error==1132)
		return "指定的基址或文件偏移量没有适当对齐。";
	if(error==1140)
		return "改变系统供电状态的尝试被另一应用程序或驱动程序否决。";
	if(error==1141)
		return "系统 BIOS 改变系统供电状态的尝试失败。";
	if(error==1142)
		return "试图在一文件上创建超过系统允许数额的链接。";
	if(error==1150)
		return "指定程序要求更新的 Windows 版本。";
	if(error==1151)
		return "指定程序不是 Windows 或 MS-DOS 程序。";
	if(error==1152)
		return "只能启动该指定程序的一个实例。";
	if(error==1153)
		return "该指定程序适用于旧的 Windows 版本。";
	if(error==1154)
		return "执行该应用程序所需的库文件之一被损坏。";
	if(error==1155)
		return "没有应用程序与此操作的指定文件有关联。";
	if(error==1156)
		return "在输送指令到应用程序的过程中出现错误。　";
	if(error==1157)
		return "执行该应用程序所需的库文件之一无法找到。";
	if(error==1158)
		return "当前程序已使用了 Window 管理器对象的系统允许的所有句柄。";
	if(error==1159)
		return "消息只能与同步操作一起使用。";
	if(error==1160)
		return "指出的源元素没有媒体。";
	if(error==1161)
		return "指出的目标元素已包含媒体。";
	if(error==1162)
		return "指出的元素不存在。";
	if(error==1163)
		return "指出的元素是未显示的存储资源的一部分。";
	if(error==1164)
		return "显示设备需要重新初始化，因为硬件有错误。";
	if(error==1165)
		return "设备显示在尝试进一步操作之前需要清除。";
	if(error==1166)
		return "设备显示它的门仍是打开状态。";
	if(error==1167)
		return "设备没有连接。";
	if(error==1168)
		return "找不到元素。";
	if(error==1169)
		return "索引中没有同指定项相匹配的项。";
	if(error==1170)
		return "在对象上不存在指定的属性集。";
	if(error==1171)
		return "传递到 GetMouseMovePoints 的点不在缓冲区中。";
	if(error==1172)
		return "跟踪(工作站)服务没运行。";
	if(error==1173)
		return "找不到卷 ID。";
	if(error==1175)
		return "无法删除要被替换的文件。";
	if(error==1176)
		return "无法将替换文件移到要被替换的文件。要被替换的文件保持原来的名称。";
	if(error==1177)
		return "无法将替换文件移到要被替换的文件。要被替换的文件已被重新命名为备份名称。";
	if(error==1178)
		return "卷更改记录被删除。";
	if(error==1179)
		return "卷更改记录服务不处于活动中。";
	if(error==1180)
		return "找到一份文件，但是可能不是正确的文件。";
	if(error==1181)
		return "日志项从日志中被删除。";
	if(error==1200)
		return "指定的设备名无效。";
	if(error==1201)
		return "设备当前未连接上，但其为一个记录连接。";
	if(error==1202)
		return "企图记录先前已被记录的设备。";
	if(error==1203)
		return "无任何网络提供程序接受指定的网络路径。";
	if(error==1204)
		return "指定的网络提供程序名称无效。";
	if(error==1205)
		return "无法打开网络连接配置文件。";
	if(error==1206)
		return "网络连接配置文件损坏。";
	if(error==1207)
		return "无法枚举空载体。";
	if(error==1208)
		return "发生扩展错误。";
	if(error==1209)
		return "指定的组名格式无效。";
	if(error==1210)
		return "指定的计算机名格式无效。";
	if(error==1211)
		return "指定的事件名格式无效。";
	if(error==1212)
		return "指定的域名格式无效。";
	if(error==1213)
		return "指定的服务名格式无效。";
	if(error==1214)
		return "指定的网络名格式无效。";
	if(error==1215)
		return "指定的共享名格式无效。";
	if(error==1216)
		return "指定的密码格式无效。";
	if(error==1217)
		return "指定的消息名格式无效。";
	if(error==1218)
		return "指定的消息目标格式无效。";
	if(error==1219)
		return "提供的凭据与已存在的凭据集冲突。";
	if(error==1220)
		return "企图创建网络服务器的会话，但已对该服务器创建过多的会话。";
	if(error==1221)
		return "工作组或域名已由网络上的另一部计算机使用。";
	if(error==1222)
		return "网络未连接或启动。";
	if(error==1223)
		return "操作已被用户取消。";
	if(error==1224)
		return "请求的操作无法在使用用户映射区域打开的文件上执行。";
	if(error==1225)
		return "远程系统拒绝网络连接。";
	if(error==1226)
		return "网络连接已被适当地关闭了。";
	if(error==1227)
		return "网络传输终结点已有与其关联的地址。";
	if(error==1228)
		return "地址仍未与网络终结点关联。";
	if(error==1229)
		return "企图在不存在的网络连接上进行操作。";
	if(error==1230)
		return "企图在使用中的网络连接上进行无效的操作。";
	if(error==1231)
		return "不能访问网络位置。有关网络排除故障的信息，请参阅 Windows 帮助。";
	if(error==1232)
		return "不能访问网络位置。有关网络排除故障的信息，请参阅 Windows 帮助。";
	if(error==1233)
		return "不能访问网络位置。有关网络排除故障的信息，请参阅 Windows 帮助。";
	if(error==1234)
		return "没有任何服务正在远程系统上的目标网络终结点上操作。";
	if(error==1235)
		return "请求被终止。";
	if(error==1236)
		return "由本地系统终止网络连接。";
	if(error==1237)
		return "操作无法完成。应该重试。";
	if(error==1238)
		return "因为已达到此帐户的最大同时连接数限制，所以无法连接服务器。";
	if(error==1239)
		return "试图在这个帐户未被授权的时间内登录。";
	if(error==1240)
		return "此帐户并未得到从这个工作站登录的授权。";
	if(error==1241)
		return "请求的操作不能使用这个网络地址。";
	if(error==1242)
		return "服务器已经注册。";
	if(error==1243)
		return "指定的服务不存在。";
	if(error==1244)
		return "因为用户还未被验证，不能执行所要求的操作。";
	if(error==1245)
		return "因为用户还未登录网络，不能执行所要求的操作。指定的服务不存在。";
	if(error==1246)
		return "正在继续工作。";
	if(error==1247)
		return "试图进行初始操作，但是初始化已完成。";
	if(error==1248)
		return "没有更多的本地设备。　";
	if(error==1249)
		return "指定的站点不存在。";
	if(error==1250)
		return "具有指定名称的域控制器已经存在。";
	if(error==1251)
		return "只有连接到服务器上时，该操作才受支持。";
	if(error==1252)
		return "即使没有改动，组策略框架也应该调用扩展。";
	if(error==1253)
		return "指定的用户没有一个有效的配置文件。";
	if(error==1254)
		return "Microsoft Small Business Server 不支持此操作。";
	if(error==1300)
		return "并非所有被引用的特权都指派给呼叫方。";
	if(error==1301)
		return "帐户名和安全标识间的某些映射未完成。";
	if(error==1302)
		return "没有为该帐户特别设置系统配额限制。";
	if(error==1303)
		return "没有可用的加密密钥。返回了一个已知加密密钥。";
	if(error==1304)
		return "密码太复杂，无法转换成 LAN Manager 密码。返回的 LAN Manager 密码为空字符串。";
	if(error==1305)
		return "修订级别未知。";
	if(error==1306)
		return "表明两个修订级别是不兼容的。";
	if(error==1307)
		return "这个安全标识不能指派为此对象的所有者。";
	if(error==1308)
		return "这个安全标识不能指派为对象的主要组。";
	if(error==1309)
		return "当前并未模拟客户的线程试图操作模拟令牌。";
	if(error==1310)
		return "组可能未被禁用。";
	if(error==1311)
		return "当前没有可用的登录服务器来服务登录请求。";
	if(error==1312)
		return "指定的登录会话不存在。可能已被终止。";
	if(error==1313)
		return "指定的特权不存在。";
	if(error==1314)
		return "客户没有所需的特权。";
	if(error==1315)
		return "提供的名称并非正确的帐户名形式。";
	if(error==1316)
		return "指定的用户已存在。";
	if(error==1317)
		return "指定的用户不存在。";
	if(error==1318)
		return "指定的组已存在。";
	if(error==1319)
		return "指定的组不存在。";
	if(error==1320)
		return "指定的用户帐户已是指定组的成员，或是因为组包含成员所以无法删除指定的组。";
	if(error==1321)
		return "指定的用户帐户不是指定组帐户的成员。";
	if(error==1322)
		return "无法禁用或删除最后剩余的系统管理帐户。";
	if(error==1323)
		return "无法更新密码。提供作为当前密码的值不正确。";
	if(error==1324)
		return "无法更新密码。提供给新密码的值包含密码中不允许的值。";
	if(error==1325)
		return "无法更新密码。为新密码提供的值不符合字符域的长度、复杂性或历史要求。";
	if(error==1326)
		return "登录失败: 未知的用户名或错误密码。";
	if(error==1327)
		return "登录失败: 用户帐户限制。";
	if(error==1328)
		return "登录失败: 违反帐户登录时间限制。";
	if(error==1329)
		return "登录失败: 不允许用户登录到此计算机。";
	if(error==1330)
		return "登录失败: 指定的帐户密码已过期。";
	if(error==1331)
		return "登录失败: 禁用当前的帐户。";
	if(error==1332)
		return "帐户名与安全标识间无任何映射完成。";
	if(error==1333)
		return "一次请求过多的本地用户标识符(LUIDs)。";
	if(error==1334)
		return "无更多可用的本地用户标识符(LUIDs)。";
	if(error==1335)
		return "对于该特别用法，安全 ID 的次级授权部分无效。";
	if(error==1336)
		return "访问控制列表(ACL)结构无效。";
	if(error==1337)
		return "安全 ID 结构无效。";
	if(error==1338)
		return "安全描述符结构无效。";
	if(error==1340)
		return "无法创建固有的访问控制列表(ACL)或访问控制项目(ACE)。";
	if(error==1341)
		return "服务器当前已禁用。";
	if(error==1342)
		return "服务器当前已启用。";
	if(error==1343)
		return "提供给识别代号颁发机构的值为无效值。";
	if(error==1344)
		return "无更多可用的内存以更新安全信息。";
	if(error==1345)
		return "指定属性无效，或与整个群体的属性不兼容。";
	if(error==1346)
		return "指定的模拟级别无效， 或所提供的模拟级别无效。";
	if(error==1347)
		return "无法打开匿名级安全令牌。";
	if(error==1348)
		return "请求的验证信息类别无效。";
	if(error==1349)
		return "令牌的类型对其尝试使用的方法不适当。";
	if(error==1350)
		return "无法在与安全性无关联的对象上运行安全性操作。";
	if(error==1351)
		return "未能从域控制器读取配置信息，或者是因为机器不可使用，或者是访问被拒绝。";
	if(error==1352)
		return "安全帐户管理器(SAM)或本地安全颁发机构(LSA)服务器处于运行安全操作的错误状态。";
	if(error==1353)
		return "域处于运行安全操作的错误状态。";
	if(error==1354)
		return "此操作只对域的主要域控制器可行。";
	if(error==1355)
		return "指定的域不存在，或无法联系。";
	if(error==1356)
		return "指定的域已存在。";
	if(error==1357)
		return "试图超出每服务器域个数的限制。";
	if(error==1358)
		return "无法完成请求操作，因为磁盘上的严重介质失败或数据结构损坏。";
	if(error==1359)
		return "出现了内部错误。";
	if(error==1360)
		return "通用访问类型包含于已映射到非通用类型的访问掩码中。";
	if(error==1361)
		return "安全描述符格式不正确 (绝对或自相关的)。";
	if(error==1362)
		return "请求操作只限制在登录进程中使用。调用进程未注册为一个登录进程。";
	if(error==1363)
		return "无法使用已在使用中的标识启动新的会话。";
	if(error==1364)
		return "未知的指定验证数据包。";
	if(error==1365)
		return "登录会话并非处于与请求操作一致的状态中。";
	if(error==1366)
		return "登录会话标识已在使用中。";
	if(error==1367)
		return "登录请求包含无效的登录类型值。";
	if(error==1368)
		return "在使用命名管道读取数据之前，无法经由该管道模拟。";
	if(error==1369)
		return "注册表子树的事务处理状态与请求状态不一致。";
	if(error==1370)
		return "安全性数据库内部出现损坏。";
	if(error==1371)
		return "无法在内置帐户上运行此操作。";
	if(error==1372)
		return "无法在内置特殊组上运行此操作。";
	if(error==1373)
		return "无法在内置特殊用户上运行此操作。";
	if(error==1374)
		return "无法从组中删除用户，因为当前组为用户的主要组。";
	if(error==1375)
		return "令牌已作为主要令牌使用。";
	if(error==1376)
		return "指定的本地组不存在。";
	if(error==1377)
		return "指定的帐户名不是本地组的成员。";
	if(error==1378)
		return "指定的帐户名已是本地组的成员。";
	if(error==1379)
		return "指定的本地组已存在。";
	if(error==1380)
		return "登录失败: 未授予用户在此计算机上的请求登录类型。";
	if(error==1381)
		return "已超过在单一系统中可保存机密的最大个数。";
	if(error==1382)
		return "机密的长度超过允许的最大长度。";
	if(error==1383)
		return "本地安全颁发机构数据库内部包含不一致性。";
	if(error==1384)
		return "在尝试登录的过程中，用户的安全上下文积累了过多的安全标识。";
	if(error==1385)
		return "登录失败: 未授予用户在此计算机上的请求登录类型。";
	if(error==1386)
		return "更改用户密码时需要交叉加密密码。";
	if(error==1387)
		return "由于成员不存在，无法将成员添加到本地组中，也无法从本地组将其删除。";
	if(error==1388)
		return "无法将新成员加入到本地组中，因为成员的帐户类型错误。";
	if(error==1389)
		return "已指定过多的安全标识。";
	if(error==1390)
		return "更改此用户密码时需要交叉加密密码。";
	if(error==1391)
		return "表明 ACL 未包含任何可承继的组件。";
	if(error==1392)
		return "文件或目录损坏且无法读取。";
	if(error==1393)
		return "磁盘结构损坏且无法读取。";
	if(error==1394)
		return "无任何指定登录会话的用户会话项。";
	if(error==1395)
		return "正在访问的服务有连接数目标授权限制。这时候已经无法再连接，原因是已经到达可接受的连接数目上限。";
	if(error==1396)
		return "登录失败: 该目标帐户名称不正确。";
	if(error==1397)
		return "相互身份验证失败。该服务器在域控制器的密码过期。";
	if(error==1398)
		return "在客户机和服务器之间有一个时间差。";
	if(error==1400)
		return "无效的窗口句柄。";
	if(error==1401)
		return "无效的菜单句柄。";
	if(error==1402)
		return "无效的光标句柄。";
	if(error==1403)
		return "无效的加速器表句柄。";
	if(error==1404)
		return "无效的挂钩句柄。";
	if(error==1405)
		return "无效的多重窗口位置结构句柄。";
	if(error==1406)
		return "无法创建最上层子窗口。";
	if(error==1407)
		return "找不到窗口类别。";
	if(error==1408)
		return "无效窗口；它属于另一线程。";
	if(error==1409)
		return "热键已注册。";
	if(error==1410)
		return "类别已存在。";
	if(error==1411)
		return "类别不存在。";
	if(error==1412)
		return "类别仍有打开的窗口。";
	if(error==1413)
		return "无效索引。";
	if(error==1414)
		return "无效的图标句柄。";
	if(error==1415)
		return "使用专用 DIALOG 窗口字。";
	if(error==1416)
		return "找不到列表框标识。";
	if(error==1417)
		return "找不到通配字符。";
	if(error==1418)
		return "线程没有打开的剪贴板。";
	if(error==1419)
		return "没有注册热键。";
	if(error==1420)
		return "窗口不是合法的对话窗口。";
	if(error==1421)
		return "找不到控件 ID。";
	if(error==1422)
		return "因为没有编辑控制，所以组合框的消息无效。";
	if(error==1423)
		return "窗口不是组合框。";
	if(error==1424)
		return "高度必须小于 256。";
	if(error==1425)
		return "无效的设备上下文(DC)句柄。";
	if(error==1426)
		return "无效的挂接程序类型。";
	if(error==1427)
		return "无效的挂接程序。";
	if(error==1428)
		return "没有模块句柄无法设置非本机的挂接。";
	if(error==1429)
		return "此挂接程序只可整体设置。";
	if(error==1430)
		return "Journal Hook 程序已安装。";
	if(error==1431)
		return "挂接程序尚未安装。";
	if(error==1432)
		return "单一选择列表框的无效消息。";
	if(error==1433)
		return "LB_SETCOUNT 发送到非被动的列表框。";
	if(error==1434)
		return "此列表框不支持 Tab 键宽度。";
	if(error==1435)
		return "无法毁坏由另一个线程创建的对象。";
	if(error==1436)
		return "子窗口没有菜单。";
	if(error==1437)
		return "窗口没有系统菜单。";
	if(error==1438)
		return "无效的消息对话框样式。";
	if(error==1439)
		return "无效的系统范围内的 (SPI_*) 参数。";
	if(error==1440)
		return "已锁定屏幕。";
	if(error==1441)
		return "多重窗口位置结构中窗口的所有句柄必须具有相同的上层。";
	if(error==1442)
		return "窗口不是子窗口。";
	if(error==1443)
		return "无效的 GW_* 命令。";
	if(error==1444)
		return "无效的线程标识。";
	if(error==1445)
		return "无法处理非多重文档界面 (MDI) 窗口中的消息。";
	if(error==1446)
		return "弹出式菜单已经激活。";
	if(error==1447)
		return "窗口没有滚动条。";
	if(error==1448)
		return "滚动条范围不可大于 MAXLONG。";
	if(error==1449)
		return "无法以指定的方式显示或删除窗口。";
	if(error==1450)
		return "系统资源不足，无法完成请求的服务。";
	if(error==1451)
		return "系统资源不足，无法完成请求的服务。";
	if(error==1452)
		return "系统资源不足，无法完成请求的服务。";
	if(error==1453)
		return "配额不足，无法完成请求的服务。";
	if(error==1454)
		return "配额不足，无法完成请求的服务。";
	if(error==1455)
		return "页面文件太小，无法完成操作。";
	if(error==1456)
		return "找不到菜单项。";
	if(error==1457)
		return "键盘布局句柄无效。";
	if(error==1458)
		return "不允许使用挂钩类型。";
	if(error==1459)
		return "该操作需要交互式窗口工作站。";
	if(error==1460)
		return "由于超时时间已过，该操作返回。";
	if(error==1461)
		return "无效监视器句柄。";
	if(error==1500)
		return "事件日志文件损坏。";
	if(error==1501)
		return "无法打开事件日志文件，事件日志服务没有启动。";
	if(error==1502)
		return "事件日志文件已满。";
	if(error==1503)
		return "事件日志文件已在读取间更改。";
	if(error==1601)
		return "无法访问 Windows 安装服务。请与技术支持人员联系，确认 Windows 安装服务是否注册正确。";
	if(error==1602)
		return "用户取消了安装。";
	if(error==1603)
		return "安装时发生严重错误";
	if(error==1604)
		return "安装已挂起，未完成。";
	if(error==1605)
		return "这个操作只对当前安装的产品有效。";
	if(error==1606)
		return "功能 ID 未注册。";
	if(error==1607)
		return "组件 ID 并未注册。";
	if(error==1608)
		return "未知属性。";
	if(error==1609)
		return "句柄处于不正确的状态。";
	if(error==1610)
		return "这个产品的配置数据已损坏。请与技术支持人员联系。";
	if(error==1611)
		return "组件限制语不存在。";
	if(error==1612)
		return "这个产品的安装来源无法使用。请验证来源是否存在，是否可以访问。";
	if(error==1613)
		return "Windows 安装服务无法安装这个安装程序包。您必须安装含有 Windows 安装服务新版本的 Windows Service Park。";
	if(error==1614)
		return "没有卸载产品。";
	if(error==1615)
		return "SQL 查询语法不正确或不被支持。";
	if(error==1616)
		return "记录字符域不存在。";
	if(error==1617)
		return "设备已被删除.";
	if(error==1618)
		return "正在进行另一个安装操作。请在继续这个安装操作之前完成那个操作。";
	if(error==1619)
		return "未能打开这个安装程序包。请验证程序包是否存在，是否可以访问；或者与应用程序供应商联系，验证这是否是有效的 Windows 安装服务程序包。";
	if(error==1620)
		return "未能打开这个安装程序包。请与应用程序供应商联系，验证这是否是有效的 Windows 安装服务程序包。";
	if(error==1621)
		return "启动 Windows 安装服务用户界面时有错误。请与技术支持人员联系。";
	if(error==1622)
		return "打开安装日志文件的错误。请验证指定的日志文件位置是否存在，是否可以写入。";
	if(error==1623)
		return "安装程序包的语言不受系统支持。";
	if(error==1624)
		return "应用变换时的错误。请验证指定的变换路径是否有效。";
	if(error==1625)
		return "系统策略禁止这个安装。请与系统管理员联系。";
	if(error==1626)
		return "无法执行函数。";
	if(error==1627)
		return "执行期间，函数出了问题。";
	if(error==1628)
		return "指定了无效的或未知的表格。";
	if(error==1629)
		return "提供的数据类型不对。";
	if(error==1630)
		return "这个类型的数据不受支持。";
	if(error==1631)
		return "Windows 安装服务未能启动。请与技术支持人员联系。";
	if(error==1632)
		return "临时文件夹已满或无法使用。请验证临时文件夹是否存在，是否可以写入。";
	if(error==1633)
		return "这个处理器类型不支持该安装程序包。请与产品供应商联系。";
	if(error==1634)
		return "组件没有在这台计算机上使用。";
	if(error==1635)
		return "无法打开修补程序包。请验证修补程序包是否存在，是否可以访问；或者与应用程序供应商联系，验证这是否是Windows 安装服务的修补程序包。";
	if(error==1636)
		return "无法打开修补程序包。请与应用程序供应商联系，验证这是否是 Windows 安装服务的修补程序包。";
	if(error==1637)
		return "Windows 安装服务无法处理这个插入程序包。您必须安装含有 Windows 安装服务新版本的 Windows Service Pack。";
	if(error==1638)
		return "已安装这个产品的另一个版本。这个版本的安装无法继续。要配置或删除这个产品的现有版本，请用“控制面板”上的“添加/删除程序”。";
	if(error==1639)
		return "无效的命令行参数。有关详细的命令行帮助，请查阅 Windows 安装服务的 SDK。";
	if(error==1640)
		return "在终端服务远程会话期间，只有管理员有添加、删除或配置服务器软件的权限。如果您要在服务器上安装或配置软件，请与网络管理员联系。";
	if(error==1641)
		return "要求的操作已成功结束。要使改动生效，必须重新启动系统。";
	if(error==1642)
		return "Windows 安装服务无法安装升级修补程序，因为被升级的程序可能会丢失或是升级修补程序可能更新此程序的一个不同版本。请确认要被升级的程序在您的计算机上且您的升级修补程序是正确的。";
	if(error==1700)
		return "串绑定无效。";
	if(error==1701)
		return "绑定句柄类型不正确。";
	if(error==1702)
		return "绑定句柄无效。";
	if(error==1703)
		return "不支持 RPC 协议序列。";
	if(error==1704)
		return "RPC 协议序列无效。";
	if(error==1705)
		return "字符串通用唯一标识 (UUID) 无效。";
	if(error==1706)
		return "终结点格式无效。";
	if(error==1707)
		return "网络地址无效。";
	if(error==1708)
		return "找不到终结点。";
	if(error==1709)
		return "超时值无效。";
	if(error==1710)
		return "找不到对象通用唯一标识(UUID)。";
	if(error==1711)
		return "对象通用唯一标识 (UUID)已注册。";
	if(error==1712)
		return "类型通用唯一标识(UUID)已注册。";
	if(error==1713)
		return "RPC 服务器已在侦听。";
	if(error==1714)
		return "未登记任何协议序列。";
	if(error==1715)
		return "RPC 服务器未在侦听。";
	if(error==1716)
		return "未知的管理器类型。";
	if(error==1717)
		return "未知的界面。";
	if(error==1718)
		return "没有任何链接。";
	if(error==1719)
		return "无任何协议顺序。";
	if(error==1720)
		return "无法创建终结点。";
	if(error==1721)
		return "资源不足，无法完成此操作。";
	if(error==1722)
		return "RPC 服务器不可用。";
	if(error==1723)
		return "RPC 服务器过忙以致无法完成此操作。";
	if(error==1724)
		return "网络选项无效。";
	if(error==1725)
		return "在此线程中，没有使用中的远程过程调用。";
	if(error==1726)
		return "远程过程调用失败。";
	if(error==1727)
		return "远程过程调用失败且未运行。";
	if(error==1728)
		return "远程过程调用(RPC)协议出错。";
	if(error==1730)
		return "RPC 服务器不支持传送语法。";
	if(error==1732)
		return "不支持通用唯一标识(UUID)类型。";
	if(error==1733)
		return "标记无效。";
	if(error==1734)
		return "数组边界无效。";
	if(error==1735)
		return "链接不包含项目名称。";
	if(error==1736)
		return "名称语法无效。";
	if(error==1737)
		return "不支持名称语法。";
	if(error==1739)
		return "没有可用来创建通用唯一标识 (UUID)的网络地址。";
	if(error==1740)
		return "终结点是一份备份。";
	if(error==1741)
		return "未知的验证类型。";
	if(error==1742)
		return "调用的最大个数太小。";
	if(error==1743)
		return "字符串太长。";
	if(error==1744)
		return "找不到 RPC 协议顺序。";
	if(error==1745)
		return "过程号超出范围。";
	if(error==1746)
		return "绑定不包含任何验证信息。";
	if(error==1747)
		return "未知的验证服务。";
	if(error==1748)
		return "未知的验证级别。";
	if(error==1749)
		return "安全上下文无效。";
	if(error==1750)
		return "未知的授权服务。";
	if(error==1751)
		return "项目无效。";
	if(error==1752)
		return "服务器终结点无法运行操作。";
	if(error==1753)
		return "终结点映射表中无更多的可用终结点。";
	if(error==1754)
		return "未导出任何界面。";
	if(error==1755)
		return "项目名称不完整。";
	if(error==1756)
		return "版本选项无效。";
	if(error==1757)
		return "没有其他成员。";
	if(error==1758)
		return "没有内容未导出。";
	if(error==1759)
		return "接口没有找到。";
	if(error==1760)
		return "项目已存在。";
	if(error==1761)
		return "找不到项目。";
	if(error==1762)
		return "无可用的名称服务。";
	if(error==1763)
		return "网络地址族无效。";
	if(error==1764)
		return "不支持请求的操作。";
	if(error==1765)
		return "无可用的安全上下文以允许模拟。";
	if(error==1766)
		return "远程过程调用(RPC)中发生内部错误。";
	if(error==1767)
		return "RPC 服务器试图以零除整数。";
	if(error==1768)
		return "RPC 服务器中发生地址错误。";
	if(error==1769)
		return "RPC 服务器上的浮点操作导至以零做除数。";
	if(error==1770)
		return "RPC 服务器上发生浮点下溢。";
	if(error==1771)
		return "RPC 服务器上发生浮点上溢。";
	if(error==1772)
		return "自动句柄绑定的可用 RPC 服务器列表已用完。";
	if(error==1773)
		return "无法打开字符翻译表文件。";
	if(error==1774)
		return "包含字符翻译表的文件少于512 字节。";
	if(error==1775)
		return "在远程过程调用时，将空的上下文句柄从客户传递到主机。";
	if(error==1777)
		return "在远程过程调用时，上下文句柄已更改。";
	if(error==1778)
		return "传递到远程过程调用的绑定句柄不相符。";
	if(error==1779)
		return "承接体无法获得远程过程调用句柄。";
	if(error==1780)
		return "传递空引用指针到承接体。";
	if(error==1781)
		return "列举值超出范围。";
	if(error==1782)
		return "字节计数太小。";
	if(error==1783)
		return "承接体接收到坏数据。";
	if(error==1784)
		return "提供给请求操作的用户缓冲区无效。";
	if(error==1785)
		return "磁盘媒体无法识别。可能未被格式化。";
	if(error==1786)
		return "工作站没有信任机密。";
	if(error==1787)
		return "服务器上的安全数据库没有此工作站信任关系的计算机帐户。";
	if(error==1788)
		return "主域和受信域间的信任关系失败。";
	if(error==1789)
		return "此工作站和主域间的信任关系失败。";
	if(error==1790)
		return "网络登录失败。";
	if(error==1791)
		return "此线程的远程过程调用已在进行中。";
	if(error==1792)
		return "试图登录，但是网络登录服务没有启动。";
	if(error==1793)
		return "用户帐户到期。";
	if(error==1794)
		return "转发程序已被占用且无法卸载。";
	if(error==1795)
		return "指定的打印机驱动程序已安装。";
	if(error==1796)
		return "指定的端口未知。";
	if(error==1797)
		return "未知的打印机驱动程序。";
	if(error==1798)
		return "未知的打印机处理器。";
	if(error==1799)
		return "指定的分隔页文件无效。";
	if(error==1800)
		return "指定的优先级无效。";
	if(error==1801)
		return "打印机名无效。";
	if(error==1802)
		return "打印机已存在。";
	if(error==1803)
		return "打印机命令无效。";
	if(error==1804)
		return "指定的数据类型无效。";
	if(error==1805)
		return "指定的环境无效。";
	if(error==1806)
		return "没有更多的绑定。";
	if(error==1807)
		return "所用帐户为域间信任帐户。请使用您的全局用户帐户或本地用户帐户来访问这台服务器。";
	if(error==1808)
		return "所用帐户是一个计算机帐户。使用您的全局用户帐户或本地用户帐户来访问此服务器。";
	if(error==1809)
		return "已使用的帐户为服务器信任帐户。使用您的全局用户帐户或本地用户帐户来访问此服务器。";
	if(error==1810)
		return "指定域的名称或安全标识(SID)与该域的信任信息不一致。";
	if(error==1811)
		return "服务器在使用中且无法卸载。";
	if(error==1812)
		return "指定的映像文件不包含资源区域。";
	if(error==1813)
		return "找不到映像文件中指定的资源类型。";
	if(error==1814)
		return "找不到映像文件中指定的资源名。";
	if(error==1815)
		return "找不到映像文件中指定的资源语言标识。";
	if(error==1816)
		return "配额不足，无法处理此命令。";
	if(error==1817)
		return "未登记任何界面。";
	if(error==1818)
		return "远程过程调用被取消。";
	if(error==1819)
		return "绑定句柄不包含所有需要的信息。";
	if(error==1820)
		return "在远程过程调用过程中通讯失败。";
	if(error==1821)
		return "不支持请求的验证级别。";
	if(error==1822)
		return "未登记任何主名称。";
	if(error==1823)
		return "指定的错误不是有效的 Windows RPC 错误码。";
	if(error==1824)
		return "已配置一个只在这部计算机上有效的 UUID。";
	if(error==1825)
		return "发生一个安全包特有的错误。";
	if(error==1826)
		return "线程未取消。";
	if(error==1827)
		return "无效的编码/解码句柄操作。";
	if(error==1828)
		return "序列化包装的版本不兼容。";
	if(error==1829)
		return "RPC 承接体的版本不兼容。";
	if(error==1830)
		return "RPC 管道对象无效或已损坏。";
	if(error==1831)
		return "试图在 RPC 管道物件上进行无效操作。";
	if(error==1832)
		return "不被支持的 RPC 管道版本。";
	if(error==1898)
		return "找不到该组成员。";
	if(error==1899)
		return "无法创建终结点映射表数据库项。";
	if(error==1900)
		return "对象通用唯一标识 (UUID) 为 nil UUID。";
	if(error==1901)
		return "指定的时间无效。";
	if(error==1902)
		return "指定的格式名称无效。";
	if(error==1903)
		return "指定的格式大小无效。";
	if(error==1904)
		return "指定的打印机句柄正等候在";
	if(error==1905)
		return "已删除指定的打印机。";
	if(error==1906)
		return "打印机的状态无效。";
	if(error==1907)
		return "在第一次登录之前，必须更改用户密码。";
	if(error==1908)
		return "找不到此域的域控制器。";
	if(error==1909)
		return "引用的帐户当前已锁定，且可能无法登录。";
	if(error==1910)
		return "没有发现指定的此对象导出者";
	if(error==1911)
		return "没有发现指定的对象。";
	if(error==1912)
		return "没有发现指定的对象解析器。";
	if(error==1913)
		return "一些待发数据仍停留在请求缓冲区内。";
	if(error==1914)
		return "无效的异步远程过程调用句柄。";
	if(error==1915)
		return "这个操作的异步 RPC 调用句柄不正确。";
	if(error==1916)
		return "RPC 管道对象已经关闭。";
	if(error==1917)
		return "在 RPC 调用完成之前全部的管道都已处理完成。";
	if(error==1918)
		return "没有其他可用的数据来自 RPC 管道。";
	if(error==1919)
		return "这个机器没有可用的站点名。";
	if(error==1920)
		return "系统无法访问此文件。";
	if(error==1921)
		return "系统无法辨识文件名。";
	if(error==1922)
		return "项目不是所要的类型。";
	if(error==1923)
		return "无法将所有对象的 UUID 导出到指定的项。";
	if(error==1924)
		return "无法将界面导出到指定的项。";
	if(error==1925)
		return "无法添加指定的配置文件项。";
	if(error==1926)
		return "无法添加指定的配置文件元素。";
	if(error==1927)
		return "无法删除指定的配置文件元素。";
	if(error==1928)
		return "无法添加组元素。";
	if(error==1929)
		return "无法删除组元素。";
	if(error==2000)
		return "无效的像素格式。";
	if(error==2001)
		return "指定的驱动程序无效。";
	if(error==2002)
		return "窗口样式或类别属性对此操作无效。";
	if(error==2003)
		return "不支持请求的图元操作。";
	if(error==2004)
		return "不支持请求的变换操作。";
	if(error==2005)
		return "不支持请求的剪切操作。";
	if(error==2010)
		return "指定的颜色管理模块无效。";
	if(error==2011)
		return "制定的颜色文件配置无效。";
	if(error==2012)
		return "找不到指定的标识。";
	if(error==2013)
		return "找不到所需的标识。";
	if(error==2014)
		return "指定的标识已经存在。";
	if(error==2015)
		return "指定的颜色文件配置与任何设备都不相关。";
	if(error==2016)
		return "找不到该指定的颜色文件配置";
	if(error==2017)
		return "指定的颜色空间无效。";
	if(error==2018)
		return "图像颜色管理没有启动。";
	if(error==2019)
		return "在删除该颜色传输时有一个错误。";
	if(error==2020)
		return "该指定的颜色传输无效。";
	if(error==2021)
		return "该指定的变换与位图的颜色空间不匹配。";
	if(error==2022)
		return "该指定的命名颜色索引在配置文件中不存在。";
	if(error==2102)
		return "没有安装工作站驱动程序。";
	if(error==2103)
		return "无法定位服务器。";
	if(error==2104)
		return "发生内部错误，网络无法访问共享内存段。";
	if(error==2105)
		return "网络资源不足。";
	if(error==2106)
		return "工作站不支持这项操作。";
	if(error==2107)
		return "设备没有连接。";
	if(error==2108)
		return "网络连接已成功，但需要提示用户输入一个不同于原始指定的密码。";
	if(error==2114)
		return "没有启动服务器服务。";
	if(error==2115)
		return "队列空。";
	if(error==2116)
		return "设备或目录不存在。";
	if(error==2117)
		return "无法在重定向的资源上执行这项操作。";
	if(error==2118)
		return "名称已经共享。";
	if(error==2119)
		return "服务器当前无法提供所需的资源。";
	if(error==2121)
		return "额外要求的项目超过允许的上限。";
	if(error==2122)
		return "对等服务只支持两个同时操作的用户 。";
	if(error==2123)
		return "API 返回缓冲区太小。";
	if(error==2127)
		return "远程 API 错误。";
	if(error==2131)
		return "打开或读取配置文件时出错。";
	if(error==2136)
		return "发生一般网络错误。";
	if(error==2137)
		return "工作站服务的状态不一致。重新启动工作站服务之前，请先重新启动计算机。";
	if(error==2138)
		return "工作站服务没有启动。";
	if(error==2139)
		return "所需信息不可用。";
	if(error==2140)
		return "发生 Windows 2000 内部错误。";
	if(error==2141)
		return "服务器没有设置事务处理。";
	if(error==2142)
		return "远程服务器不支持请求的 API。";
	if(error==2143)
		return "事件名无效。";
	if(error==2144)
		return "网络上已经有此计算机名。请更名后重新启动。";
	if(error==2146)
		return "配置信息中找不到指定的组件。";
	if(error==2147)
		return "配置信息中找不到指定的参数。";
	if(error==2149)
		return "配置文件中有一个命令行太长。";
	if(error==2150)
		return "打印机不存在。";
	if(error==2151)
		return "打印作业不存在。";
	if(error==2152)
		return "打印机目标找不到。";
	if(error==2153)
		return "打印机目标已经存在。";
	if(error==2154)
		return "打印机队列已经存在。";
	if(error==2155)
		return "无法添加其它的打印机。";
	if(error==2156)
		return "无法添加其它的打印作业。";
	if(error==2157)
		return "无法添加其它的打印机目标。";
	if(error==2158)
		return "此打印机目标处于空闲中，不接受控制操作。";
	if(error==2159)
		return "此“打印机目标请求”包含无效的控制函数。";
	if(error==2160)
		return "打印处理程序没有响应。";
	if(error==2161)
		return "后台处理程序没有运行。";
	if(error==2162)
		return "打印目标当前的状况，无法执行这项操作。";
	if(error==2163)
		return "打印机队列当前的状况，无法执行这项操作。";
	if(error==2164)
		return "打印作业当前的状况，无法执行这项操作。";
	if(error==2165)
		return "无法为后台处理程序分配内存。";
	if(error==2166)
		return "设备驱动程序不存在。";
	if(error==2167)
		return "打印处理程序不支持这种数据类型。";
	if(error==2168)
		return "没有安装打印处理程序。";
	if(error==2180)
		return "锁定服务数据库。";
	if(error==2181)
		return "服务表已满。";
	if(error==2182)
		return "请求的服务已经启动。";
	if(error==2183)
		return "这项服务没有响应控制操作。";
	if(error==2184)
		return "服务仍未启动。";
	if(error==2185)
		return "服务名无效。";
	if(error==2186)
		return "服务没有响应控制功能。";
	if(error==2187)
		return "服务控制处于忙碌状态。";
	if(error==2188)
		return "配置文件包含无效的服务程序名。";
	if(error==2189)
		return "在当前的状况下无法控制服务。";
	if(error==2190)
		return "服务异常终止。";
	if(error==2191)
		return "这项服务无法接受请求的 \"暂停\" 或 \"停止\" 操作。";
	if(error==2192)
		return "服务控制“计划程序”在“计划表”中找不到服务名。";
	if(error==2193)
		return "无法读取服务控制计划程序管道。";
	if(error==2194)
		return "无法创建新服务的线程。";
	if(error==2200)
		return "此工作站已经登录到局域网。";
	if(error==2201)
		return "工作站没有登录到局域网。";
	if(error==2202)
		return "指定的用户名无效。";
	if(error==2203)
		return "密码参数无效。";
	if(error==2204)
		return "登录处理器没有添加消息别名。";
	if(error==2205)
		return "登录处理器没有添加消息别名。";
	if(error==2206)
		return "注销处理器没有删除消息别名。";
	if(error==2207)
		return "注销处理器没有删除消息别名。";
	if(error==2209)
		return "暂停网络登录。";
	if(error==2210)
		return "中心登录服务器发生冲突。";
	if(error==2211)
		return "服务器没有设置正确的用户路径。";
	if(error==2212)
		return "加载或运行登录脚本时出错。";
	if(error==2214)
		return "没有指定登录服务器，计算机的登录状态是单机操作。";
	if(error==2215)
		return "登录服务器找不到。";
	if(error==2216)
		return "此计算机已经有一个登录域。";
	if(error==2217)
		return "登录服务器无法验证登录。";
	if(error==2219)
		return "安全数据库找不到。";
	if(error==2220)
		return "组名找不到。";
	if(error==2221)
		return "用户名找不到。";
	if(error==2222)
		return "资源名找不到。";
	if(error==2223)
		return "组已经存在。";
	if(error==2224)
		return "帐户已经存在。";
	if(error==2225)
		return "资源使用权限清单已经存在。";
	if(error==2226)
		return "此操作只能在该域的主域控制器上执行。";
	if(error==2227)
		return "安全数据库没有启动。";
	if(error==2228)
		return "用户帐户数据库中的名称太多。";
	if(error==2229)
		return "磁盘 I/O 失败。";
	if(error==2230)
		return "已经超过每个资源 64 个项目的限制。";
	if(error==2231)
		return "不得删除带会话的用户。";
	if(error==2232)
		return "上层目录找不到。";
	if(error==2233)
		return "无法添加到安全数据库会话高速缓存段。";
	if(error==2234)
		return "这项操作不能在此特殊的组上执行。";
	if(error==2235)
		return "用户帐户数据库会话高速缓存没有记录此用户。";
	if(error==2236)
		return "用户已经属于此组。";
	if(error==2237)
		return "用户不属于此组。";
	if(error==2238)
		return "此用户帐户尚未定义。";
	if(error==2239)
		return "此用户帐户已过期。";
	if(error==2240)
		return "此用户不得从此工作站登录网络。";
	if(error==2241)
		return "这时候不允许用户登录网络。";
	if(error==2242)
		return "此用户的密码已经过期。";
	if(error==2243)
		return "此用户的密码无法更改。";
	if(error==2244)
		return "现在无法使用此密码。";
	if(error==2245)
		return "密码不满足密码策略的需要。检查最小密码长度、密码复杂性和密码历史的需求。";
	if(error==2246)
		return "此用户的密码最近才启用，现在不能更改。";
	if(error==2247)
		return "安全数据库已损坏。";
	if(error==2248)
		return "不需要更新此副本复制的网络/本地安全数据库。";
	if(error==2249)
		return "此副本复制的数据库已过时；请同步处理其中的数据。";
	if(error==2250)
		return "此网络连接不存在。";
	if(error==2251)
		return "此 asg_type 无效。";
	if(error==2252)
		return "此设备当前正在共享中。";
	if(error==2270)
		return "计算机名无法作为消息别名添加。网络上可能已经有此名称。";
	if(error==2271)
		return "信使服务已经启动。";
	if(error==2272)
		return "信使服务启动失败。";
	if(error==2273)
		return "网络上找不到此消息别名。";
	if(error==2274)
		return "此消息别名已经转发出去。";
	if(error==2275)
		return "已经添加了此消息别名，但是仍被转发。";
	if(error==2276)
		return "此消息别名已在本地存在。";
	if(error==2277)
		return "添加的消息别名已经超过数目上限。";
	if(error==2278)
		return "无法删除计算机名。";
	if(error==2279)
		return "消息无法转发回到同一个工作站。";
	if(error==2280)
		return "域消息处理器出错。";
	if(error==2281)
		return "消息已经发送出去，但是收件者已经暂停信使服务。";
	if(error==2282)
		return "消息已经发送出去，但尚未收到。";
	if(error==2283)
		return "消息别名当前正在使用中。请稍候片刻再试。";
	if(error==2284)
		return "信使服务尚未启动。";
	if(error==2285)
		return "该名称不在本地计算机上。";
	if(error==2286)
		return "网络上找不到转发的消息别名。";
	if(error==2287)
		return "远程通讯站的消息别名表已经满了。";
	if(error==2288)
		return "此别名的消息当前没有在转发中。";
	if(error==2289)
		return "广播的消息被截断。";
	if(error==2294)
		return "设备名无效。";
	if(error==2295)
		return "写入出错。";
	if(error==2297)
		return "网络上的消息别名重复。";
	if(error==2298)
		return "此消息别名会在稍后删除。";
	if(error==2299)
		return "没有从所有的网络删除消息别名。";
	if(error==2300)
		return "这项操作无法在使用多种网络的计算机上执行。";
	if(error==2310)
		return "此共享的资源不存在。";
	if(error==2311)
		return "设备没有共享。";
	if(error==2312)
		return "带此计算机名的会话不存在。";
	if(error==2314)
		return "没有用此识别号打开的文件。";
	if(error==2315)
		return "执行远程管理命令失败。";
	if(error==2316)
		return "打开远程临时文件失败。";
	if(error==2317)
		return "从远程管理命令返回的数据已经被截断成 64K。";
	if(error==2318)
		return "此设备无法同时共享为后台处理资源和非后台处理资源。";
	if(error==2319)
		return "服务器清单中的信息可能不正确";
	if(error==2320)
		return "计算机在此域未处于活动状态";
	if(error==2321)
		return "在删除共享之前，需要将该共享从分布式文件系统中删除。";
	if(error==2331)
		return "无法在此设备执行这项操作";
	if(error==2332)
		return "此设备无法共享。";
	if(error==2333)
		return "此设备未打开。";
	if(error==2334)
		return "此设备名清单无效。";
	if(error==2335)
		return "队列优先级无效。";
	if(error==2337)
		return "没有任何共享的通讯设备。";
	if(error==2338)
		return "指定的队列不存在。";
	if(error==2340)
		return "此设备清单无效。";
	if(error==2341)
		return "请求的设备无效。";
	if(error==2342)
		return "后台处理程序正在使用此设备。";
	if(error==2343)
		return "此设备已经被当成通讯设备来使用。";
	if(error==2351)
		return "此计算机名无效。";
	if(error==2354)
		return "指定的字符串及前缀太长。";
	if(error==2356)
		return "此路径组成部分无效。";
	if(error==2357)
		return "无法判断输入类型。";
	if(error==2362)
		return "类型缓冲区不够大。";
	if(error==2370)
		return "配置文件不得超过 64K。";
	if(error==2371)
		return "初始偏移量越界。";
	if(error==2372)
		return "系统无法删除当前到网络资源的连接。";
	if(error==2373)
		return "系统无法分析此文件中的命令行。";
	if(error==2374)
		return "加载配置文件时出错。/";
	if(error==2375)
		return "保存配置文件时出错，只部份地保存了配置文件。";
	if(error==2378)
		return "此日志文件在前后两次读取之间已经发生变化。";
	if(error==2380)
		return "资源路径不可以是目录。";
	if(error==2381)
		return "资源路径无效。";
	if(error==2382)
		return "目标路径无效。";
	if(error==2383)
		return "源路径及目标路径分属不同的服务器。";
	if(error==2385)
		return "请求的 Run 服务器现在暂停。";
	if(error==2389)
		return "与 Run 服务器通讯时出错。";
	if(error==2391)
		return "启动后台处理时出错。";
	if(error==2392)
		return "找不到您连接的共享资源。";
	if(error==2400)
		return "LAN 适配器号码无效。";
	if(error==2401)
		return "此网络连接有文件打开或请求挂起。";
	if(error==2402)
		return "使用中的连接仍存在。";
	if(error==2403)
		return "此共享名或密码无效。";
	if(error==2404)
		return "设备正由活动进程使用，无法断开。";
	if(error==2405)
		return "此驱动器号已在本地使用。";
	if(error==2430)
		return "指定的客户已经在指定的事件注册。";
	if(error==2431)
		return "警报表已满。";
	if(error==2432)
		return "发出的警报名称无效或不存在。";
	if(error==2433)
		return "警报接收者无效。";
	if(error==2434)
		return "用户的登录时间长短不再合法。所以已经删除用户与该服务器的会话。";
	if(error==2440)
		return "日志文件中没有请求的记录号。";
	if(error==2450)
		return "用户帐户数据库没有正确配置。";
	if(error==2451)
		return "当 Netlogon 服务正在运行时，不允许执行这项操作。";
	if(error==2452)
		return "这项操作无法在最后的管理帐户上执行。";
	if(error==2453)
		return "找不到此域的域控制器。";
	if(error==2454)
		return "无法设置此用户的登录信息。";
	if(error==2455)
		return "Netlogon 服务尚未启动。";
	if(error==2456)
		return "无法添加到用户帐户数据库。";
	if(error==2457)
		return "此服务器的时钟与主域控制器的时钟不一致。";
	if(error==2458)
		return "检测到密码不匹配。";
	if(error==2460)
		return "服务器识别码没有指定有效的服务器。";
	if(error==2461)
		return "会话标识没有指定有效的会话。";
	if(error==2462)
		return "连接识别码没有指定有效的连接。";
	if(error==2463)
		return "可用服务器表中无法再加上其它项。";
	if(error==2464)
		return "服务器已经到了支持的会话数目上限。";
	if(error==2465)
		return "服务器已经到了支持的连接数目上限。";
	if(error==2466)
		return "服务器打开的文件到了上限，无法打开更多文件。";
	if(error==2467)
		return "这台服务器没有登记替换的服务器。";
	if(error==2470)
		return "请用低级的 API (远程管理协议)。";
	if(error==2480)
		return "UPS 服务无法访问 UPS 驱动程序。";
	if(error==2481)
		return "UPS 服务设置错误。";
	if(error==2482)
		return "UPS 服务无法访问指定通讯端口 (Comm Port)。";
	if(error==2483)
		return "UPS 显示线路中断或电池不足，服务没有启动。";
	if(error==2484)
		return "UPS 服务无法执行系统关机的操作。";
	if(error==2500)
		return "下面的程序返回一个 MS-DOS 错误码:";
	if(error==2501)
		return "下面的程序需要更多的内存:";
	if(error==2502)
		return "下面程序调用了不支持的 MS-DOS 函数:";
	if(error==2503)
		return "工作站无法启动。";
	if(error==2504)
		return "下面的文件已损坏。";
	if(error==2505)
		return "启动块定义文件中没有指定引导程序。";
	if(error==2506)
		return "NetBIOS 返回错误: NCB 及 SMB 数据转储。";
	if(error==2507)
		return "磁盘 I/O 错误。";
	if(error==2508)
		return "无法替换映像参数。";
	if(error==2509)
		return "跨越磁盘扇区范围的映像参数太多。";
	if(error==2510)
		return "不是从用 /S 格式化的 MS-DOS软盘产生的映像。";
	if(error==2511)
		return "稍后会从远程重新启动。";
	if(error==2512)
		return "无法调用远程启动服务器。";
	if(error==2513)
		return "无法连接到远程启动服务器。";
	if(error==2514)
		return "无法打开远程启动服务器上的映像文件。";
	if(error==2515)
		return "正在连接到远程启动服务器...";
	if(error==2516)
		return "正在连接到远程启动服务器...";
	if(error==2517)
		return "远程启动服务已经停止，请检测错误记录文件，查明出错的原因。";
	if(error==2518)
		return "远程启动失败，请检查错误日志文件，查明出错的原因。";
	if(error==2519)
		return "不允许第二个远程启动 (Remoteboot) 资源连接。";
	if(error==2550)
		return "浏览服务设置成 MaintainServerList=No。";
	if(error==2610)
		return "因为没有网卡与这项服务一起启动，所以无法启动服务。";
	if(error==2611)
		return "因为注册表中的启动信息不正确，所以无法启动服务。";
	if(error==2612)
		return "无法启动服务，原因是它的数据库找不到或损坏。";
	if(error==2613)
		return "因为找不到 RPLFILES 共享的资源，所以无法启动服务。";
	if(error==2614)
		return "因为找不到 RPLUSER 组，所以无法启动服务。";
	if(error==2615)
		return "无法枚举服务记录。";
	if(error==2616)
		return "工作站记录信息已损坏。";
	if(error==2617)
		return "工作站记录找不到。";
	if(error==2618)
		return "其它的工作站正在使用此工作站名。";
	if(error==2619)
		return "配置文件记录已损坏。";
	if(error==2620)
		return "配置文件记录找不到。";
	if(error==2621)
		return "其它的配置文件正在使用此名称。";
	if(error==2622)
		return "有很多工作站正在使用此配置文件。";
	if(error==2623)
		return "配置记录已损坏。";
	if(error==2624)
		return "配置记录找不到。";
	if(error==2625)
		return "适配器识别记录已损坏。";
	if(error==2626)
		return "内部服务出错。";
	if(error==2627)
		return "供应商识别记录已损坏。";
	if(error==2628)
		return "启动块记录已损坏。";
	if(error==2629)
		return "找不到此工作站的用户帐户记录。";
	if(error==2630)
		return "RPLUSER 本地组找不到。";
	if(error==2631)
		return "找不到启动块记录。";
	if(error==2632)
		return "所选的配置文件与此工作站不兼容。";
	if(error==2633)
		return "其它的工作站正在使用所选的网卡。";
	if(error==2634)
		return "有些配置文件正在使用此配置。";
	if(error==2635)
		return "有数个工作站、配置文件或配置正在使用此启动块。";
	if(error==2636)
		return "服务无法制作远程启动数据库的备份。";
	if(error==2637)
		return "找不到适配器记录。";
	if(error==2638)
		return "找不到供应商记录。";
	if(error==2639)
		return "其它供应商记录正在使用此供应商名称。";
	if(error==2640)
		return "其它的启动区记录正在使用启动名称或供应商识别记录。";
	if(error==2641)
		return "其它的配置正在使用此配置名称。";
	if(error==2660)
		return "由 Dfs 服务所维护的内部数据库已损坏";
	if(error==2661)
		return "内部数据库中的一条记录已 损坏";
	if(error==2662)
		return "输入项路径与卷路径不匹配";
	if(error==2663)
		return "给定卷名已存在";
	if(error==2664)
		return "指定的服务器共享已在 Dfs 中共享";
	if(error==2665)
		return "所显示的服务器共享不支持所显示的 Dfs 卷";
	if(error==2666)
		return "此操作在非叶卷上无效。";
	if(error==2667)
		return "此操作在叶卷上无效。";
	if(error==2668)
		return "此操作不明确，因为该卷存在多服务器。";
	if(error==2669)
		return "无法创建连接点";
	if(error==2670)
		return "该服务器不是 Dfs 可识别的";
	if(error==2671)
		return "指定的重命名目标路径无效。";
	if(error==2672)
		return "指定 Dfs 卷脱线";
	if(error==2673)
		return "指定的服务器不为此卷服务";
	if(error==2674)
		return "检测到 Dfs 名中的环路";
	if(error==2675)
		return "在基于服务器的 Dfs 上不支持该操作";
	if(error==2676)
		return "这个卷已经受该指定服务器共享支持";
	if(error==2677)
		return "无法删除这个卷的上一个服务器共享支持";
	if(error==2678)
		return "Inter-Dfs 卷不支持该操作";
	if(error==2679)
		return "Dfs 服务的内部状态已经变得不一致";
	if(error==2680)
		return "Dfs 服务已经安装在指定的服务器上";
	if(error==2681)
		return "被协调的 Dfs 数据是一样的";
	if(error==2682)
		return "无法删除 Dfs 根目录卷 - 如需要请卸载 Dfs";
	if(error==2683)
		return "该共享的子目录或父目录已经存在在一个 Dfs 中";
	if(error==2690)
		return "Dfs 内部错误";
	if(error==2691)
		return "这台机器已经加入域 。";
	if(error==2692)
		return "这个机器目前未加入域。";
	if(error==2693)
		return "这台机器是域控制器，而且无法从域中退出。";
	if(error==2694)
		return "目标域控制器不支持在 OU 中创建的机器帐户。";
	if(error==2695)
		return "指定的工作组名无效";
	if(error==2696)
		return "指定的计算机名与域控制器上使用的默认语言不兼容。";
	if(error==2697)
		return "找不到指定的计算机帐户。";
	if(error==2999)
		return "这是 NERR 范围内的最后一个错误。";
	if(error==3000)
		return "指定了未知的打印监视器。";
	if(error==3001)
		return "指定的打印机驱动程序当前正在使用。";
	if(error==3002)
		return "找不到缓冲文件。";
	if(error==3003)
		return "未发送 StartDocPrinter 调用。";
	if(error==3004)
		return "未发送 AddJob 调用。";
	if(error==3005)
		return "指定的打印处理器已经安装。";
	if(error==3006)
		return "指定的打印监视器已经安装。";
	if(error==3007)
		return "该指定的打印监视器不具备所要求的功能。　";
	if(error==3008)
		return "该指定的打印监视器正在使用中。";
	if(error==3009)
		return "当打印机有作业排成队列时此操作请求是不允许的。";
	if(error==3010)
		return "请求的操作成功。直到重新启动系统前更改将不会生效。";
	if(error==3011)
		return "请求的操作成功。直到重新启动服务前更改将不会生效。";
	if(error==3012)
		return "找不到打印机。";
	if(error==3023)
		return "用户指定的关机命令文件，它的配置有问题。不过 UPS 服务已经启动。";
	if(error==3029)
		return "因为用户帐户数据库 (NET.ACC) 找不到或损坏，而且也没有可用的备份数据库，所以不能启动本地安全机制。系统不安全！";
	if(error==3037)
		return "@I *登录小时数";
	if(error==3039)
		return "已经超过一个目录中文件的副本复制的限制。";
	if(error==3040)
		return "已经超过副本复制的目录树深度限制。";
	if(error==3046)
		return "无法登录。用户当前已经登录，同时参数 TRYUSER设置为 NO。";
	if(error==3052)
		return "命令行或配置文件中没有提供必要的参数。";
	if(error==3054)
		return "无法满足资源的请求。";
	if(error==3055)
		return "系统配置有问题。";
	if(error==3056)
		return "系统出错。";
	if(error==3057)
		return "发生内部一致性的错误。";
	if(error==3058)
		return "配置文件或命令行的选项不明确。";
	if(error==3059)
		return "配置文件或命令行的参数重复。";
	if(error==3060)
		return "服务没有响应控制，DosKillProc 函数已经停止服务。";
	if(error==3061)
		return "运行服务程序时出错。";
	if(error==3062)
		return "无法启动次级服务。";
	if(error==3064)
		return "文件有问题。";
	if(error==3070)
		return "内存";
	if(error==3071)
		return "磁盘空间";
	if(error==3072)
		return "线程";
	if(error==3073)
		return "过程";
	if(error==3074)
		return "安全性失败。";
	if(error==3075)
		return "LAN Manager 根目录不正确或找不到。";
	if(error==3076)
		return "未安装网络软件。";
	if(error==3077)
		return "服务器未启动。";
	if(error==3078)
		return "服务器无法访问用户帐户数据库 (NET.ACC)。";
	if(error==3079)
		return "LANMAN 树中安装的文件不兼容。";
	if(error==3080)
		return "LANMAN/LOGS 目录无效。";
	if(error==3081)
		return "指定的域无法使用。";
	if(error==3082)
		return "另一计算机正将此计算机名当作消息别名使用。";
	if(error==3083)
		return "宣布服务器名失败。";
	if(error==3084)
		return "用户帐户数据库没有正确配置。";
	if(error==3085)
		return "服务器没有运行用户级安全功能。";
	if(error==3087)
		return "工作站设置不正确。";
	if(error==3088)
		return "查看您的错误日志文件以了解详细信息。";
	if(error==3089)
		return "无法写入此文件。";
	if(error==3090)
		return "ADDPAK 文件损坏。请删除 LANMAN/NETPROG/ADDPAK.SER后重新应用所有的 ADDPAK。";
	if(error==3091)
		return "因为没有运行 CACHE.EXE，所以无法启动 LM386 服务器。";
	if(error==3092)
		return "安全数据库中找不到这台计算机的帐户。";
	if(error==3093)
		return "这台计算机不是 SERVERS 组的成员。";
	if(error==3094)
		return "SERVERS 组没有在本地安全数据库中。";
	if(error==3095)
		return "此 Windows NT 计算机被设置为某个组的成员，并不是域的成员。此种配置下不需要运行 Netlogon 服务。";
	if(error==3096)
		return "找不到此域的 Windows NT 域控制器。";
	if(error==3098)
		return "服务无法与主域控制器进行验证。";
	if(error==3099)
		return "安全数据库文件创建日期或序号有问题。";
	if(error==3100)
		return "因为网络软件出错，所以无法执行操作。";
	if(error==3102)
		return "这项服务无法长期锁定网络控制块 (NCB) 的段。错误码就是相关数据。";
	if(error==3103)
		return "这项服务无法解除网络控制块 (NCB) 段的长期锁定。错误码就是相关数据。";
	if(error==3106)
		return "收到意外的网络控制块 (NCB)。NCB 就是相关数据。";
	if(error==3107)
		return "网络没有启动。";
	if(error==3108)
		return "NETWKSTA.SYS 的 DosDevIoctl 或 DosFsCtl 调用失败。显示的数据为以下格式:DWORD 值代表调用 Ioctl 或 FsCtl 的 CS:IP WORD 错误代码 WORD Ioctl 或 FsCtl 号";
	if(error==3111)
		return "发生意外的 NetBIOS 错误。错误码就是相关数据。";
	if(error==3112)
		return "收到的服务器消息块 (SMB) 无效。SMB 就是相关数据。";
	if(error==3114)
		return "因为缓冲区溢出，所以错误日志文件中部份的项目丢失。";
	if(error==3120)
		return "控制网络缓冲区以外资源用量的初始化参数被设置大小，因此需要的内存太多。";
	if(error==3121)
		return "服务器无法增加内存段的大小。";
	if(error==3124)
		return "服务器启动失败。三个 chdev参数必须同时为零或者同时不为零。";
	if(error==3129)
		return "服务器无法更新 AT 计划文件。文件损坏。";
	if(error==3130)
		return "服务器调用 NetMakeLMFileName 时出错。错误码就是相关数据。";
	if(error==3132)
		return "无法长期锁定服务器缓冲区。请检查交换磁盘的可用空间，然后重新启动系统以启动服务器。";
	if(error==3140)
		return "因为多次连续出现网络控制块 (NCB) 错误，所以停止服务。最后一个坏的 NCB 以原始数据形式出现。";
	if(error==3141)
		return "因为消息服务器共享的数据段被锁住，所以消息服务器已经停止运行。";
	if(error==3151)
		return "因为 VIO 调用出错，所以无法弹出显示消息。错误码就是相关数据。";
	if(error==3152)
		return "收到的服务器消息块 (SMB) 无效。SMB 就是相关数据。";
	if(error==3160)
		return "工作站信息段大于 64K。大小如下(以 DWORD 值的格式):";
	if(error==3161)
		return "工作站无法取得计算机的名称号码。";
	if(error==3162)
		return "工作站无法初始化 Async NetBIOS 线程。错误码就是相关数据。";
	if(error==3163)
		return "工作站无法打开最前面的共享段。错误码就是相关数据。";
	if(error==3164)
		return "工作站主机表已满。";
	if(error==3165)
		return "收到的邮筒服务器消息块 (SMB) 有问题，SMB 就是相关数据。";
	if(error==3166)
		return "工作站启动用户帐户数据库时出错。错误码就是相关数据。";
	if(error==3167)
		return "工作站响应 SSI 重新验证请求时出错。函数码及错误码就是相关数据。";
	if(error==3174)
		return "服务器无法读取 AT 计划文件。";
	if(error==3175)
		return "服务器发现错误的 AT 计划记录。";
	if(error==3176)
		return "服务器找不到 AT 计划文件，所以创建一个计划文件。";
	if(error==3185)
		return "因为用户帐户数据库 (NET.ACC) 找不到或损坏，而且也没有可用的备份数据库，所以不能启动本地安全机制。系统不安全！";
	if(error==3204)
		return "服务器无法创建线程。CONFIG.SYS 中的 THREADS 参数必须加大。";
	if(error==3213)
		return "已经超过一个目录中文件的副本复制的限制。";
	if(error==3214)
		return "已经超过副本复制的目录树深度限制。";
	if(error==3215)
		return "邮筒中收到的消息无法识别。";
	if(error==3217)
		return "无法登录。用户当前已经登录，同时参数 TRYUSER设置为 NO。";
	if(error==3230)
		return "检测到服务器的电源中断。";
	if(error==3231)
		return "UPS 服务已经关掉服务器。";
	if(error==3232)
		return "UPS 服务没有完成执行用户指定的关机命令文件。";
	if(error==3233)
		return "无法打开 UPS 驱动程序。错误码就是相关数据。";
	if(error==3234)
		return "电源已经恢复。";
	if(error==3235)
		return "用户指定的关机命令文件有问题。";
	if(error==3256)
		return "该项服务的动态链接库发生无法修复的错误。";
	if(error==3257)
		return "系统返回意外的错误码。错误码就是相关数据。";
	if(error==3258)
		return "容错错误日志文件 - LANROOT/LOGS/FT.LOG超过 64K。";
	if(error==3259)
		return "容错错误日志文件 - LANROOT/LOGS/FT.LOG，在被打开时就已设置更新进度位，这表示上次使用错误日志时，系统死机。";
	return "[GetLastError][ERROR]Return value is not in the lib.";
}

#endif
//https://blog.csdn.net/gooddaddy/article/details/4030468

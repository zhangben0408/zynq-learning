connect -url tcp:127.0.0.1:3121
source D:/zynq/zynq_learning/CH2_MIO_LED/CH2_MIO_LED.sdk/system_wrapper_hw_platform_0/ps7_init.tcl
targets -set -filter {jtag_cable_name =~ "Digilent Zed 210248685660" && level==0} -index 1
fpga -file D:/zynq/zynq_learning/CH2_MIO_LED/CH2_MIO_LED.sdk/system_wrapper_hw_platform_0/system_wrapper.bit
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zed 210248685660"} -index 0
loadhw -hw D:/zynq/zynq_learning/CH2_MIO_LED/CH2_MIO_LED.sdk/system_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zed 210248685660"} -index 0
stop
ps7_init
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248685660"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248685660"} -index 0
dow D:/zynq/zynq_learning/CH2_MIO_LED/CH2_MIO_LED.sdk/MIO_LED/Debug/MIO_LED.elf
configparams force-mem-access 0
bpadd -addr &main

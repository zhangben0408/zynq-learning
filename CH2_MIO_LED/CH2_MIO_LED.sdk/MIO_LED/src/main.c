#include "xgpiops.h"
#include "sleep.h"
int main()
{
	static XGpioPs psGpioInstancePtr;
	XGpioPs_Config* GpioConfigPtr;
	int iPinNumber= 7;			//LD9连接的是MIO7
	u32 uPinDirection = 0x1;	//1表示输出，0表示输入
	int xStatus;

	//--MIO的初始化
    GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	if(GpioConfigPtr == NULL)
		return XST_FAILURE;

	xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,GpioConfigPtr, GpioConfigPtr->BaseAddr);
	if(XST_SUCCESS != xStatus)
		print(" PS GPIO INIT FAILED \n\r");
	//--MIO的输入输出操作
     XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber,uPinDirection);//配置MIO输出方向
	 XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber,1);//配置MIO的第7位输出
	 while(1)
	 {
		XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 1);//点亮MIO的第7位输出1
		sleep(1);	//延时
		XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 0);//熄灭MIO的第7位输出0
		sleep(1);	//延时
	 }

    return 0;
}

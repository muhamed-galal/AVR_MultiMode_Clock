/*
 * I2C_Private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Muham
 */

#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_

#define Start_Ack						0x08	// start has been sent
#define Rep_Start_Ack					0x10	//repeated start
#define Slave_Add_Wr_Ack				0x18	//master trasnmit (slave address with write request) Ack
#define Slave_Add_Rd_Ack				0x40	//master trasmit
#define Master_Wr_Byte_Ack				0x28 	// master transmit data ack
#define Master_Rd_Byte_Ack				0x50	// master recieved data with ack
#define Master_Rd_Byte_NAck				0x58	// master recieved data without ack
#define Slave_Add_Rcvd_Rd_Req			0xA8	// slave address recieved with read request
#define Slave_Add_Rcvd_Wr_Req			0x60	// slave address recieved with write request
#define Slave_Date_Rcvd					0x80	// byte is recieved
#define Slave_Byte_Trnsmit				0xB8	// written byte is transmitted




#endif /* MCAL_I2C_I2C_PRIVATE_H_ */

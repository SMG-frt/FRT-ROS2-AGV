uint8 CANOPEN_DATATYPE_INT8 = 0x02
uint8 CANOPEN_DATATYPE_INT16 = 0x03
uint8 CANOPEN_DATATYPE_INT32 = 0x04
uint8 CANOPEN_DATATYPE_UINT8 = 0x05
uint8 CANOPEN_DATATYPE_UINT16 = 0x06
uint8 CANOPEN_DATATYPE_UINT32 = 0x07

uint8 nodeid
uint16 index
uint8 subindex
# 8 = uint8_t, 16 = uint16_t, 32 = uint32_t
uint8 canopen_datatype

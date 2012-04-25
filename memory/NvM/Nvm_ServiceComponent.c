/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

#include "NvM.h"

#if defined(CFG_NVM_USE_SERVICE_COMPONENT)

Std_ReturnType NvMService_GetErrorStatus(Nvm_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr) {
	NvM_GetErrorStatus( BlockId, (uint8*)RequestResultPtr );
	return E_OK;
}

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON )
Std_ReturnType NvMService_SetRamBlockStatus(Nvm_BlockIdType BlockId, Boolean BlockChanged) {
	Nvm_SetRamBlockStatus( BlockId, (boolean)BlockChanged );
	return E_OK;
}
#endif

#if (NVM_API_CONFIG_CLASS > NVM_API_CONFIG_CLASS_1)

Std_ReturnType NvMService_SetDataIndex(Nvm_BlockIdType BlockId, UInt8 DataIndex) {
	NvM_SetDataIndex( BlockId, (uint8)DataIndex );
	return E_OK;
}

Std_ReturnType NvMService_GetDataIndex(Nvm_BlockIdType BlockId, UInt8* DataIndexPtr) {
	NvM_GetDataIndex( BlockId, (uint8*)DataIndexPtr );
	return E_OK;
}

Std_ReturnType NvMService_ReadBlock(Nvm_BlockIdType BlockId, const DstPtrType DstPtr) {
	return NvMService_ReadBlock(BlockId, (uint8*)DstPtr), E_OK;
}

Std_ReturnType NvMService_WriteBlock(Nvm_BlockIdType BlockId, const DstPtrType SrcPtr) {
	return NvM_WriteBlock( BlockId, (uint8*)(SrcPtr) ), E_OK;
}

Std_ReturnType NvMService_RestoreBlockDefaults(Nvm_BlockIdType BlockId, const DstPtrType DstPtr) {
	return Nvm_RestoreBlockDefaults( BlockId, (uint8*)DstPtr ), E_OK;
}

#else

Std_ReturnType NvMService_SetDataIndex(Nvm_BlockIdType BlockId, UInt8 DataIndex) {
	/* Dummy */
	return E_OK;
}

Std_ReturnType NvMService_GetDataIndex(Nvm_BlockIdType BlockId, UInt8* DataIndexPtr) {
	/* Dummy */
	return E_OK;
}

Std_ReturnType NvMService_ReadBlock(Nvm_BlockIdType BlockId, const DstPtrType DstPtr) {
	/* Dummy */
	return E_OK;
}

Std_ReturnType NvMService_WriteBlock(Nvm_BlockIdType BlockId, const DstPtrType SrcPtr) {
	/* Dummy */
	return E_OK;
}

Std_ReturnType NvMService_RestoreBlockDefaults(Nvm_BlockIdType BlockId, const DstPtrType DstPtr) {
	/* Dummy */
	return E_OK;
}

#endif

#if (NVM_API_CONFIG_CLASS > NVM_API_CONFIG_CLASS_2)

Std_ReturnType NvMService_EraseBlock(Nvm_BlockIdType BlockId) {
	return NvM_EraseNvBlock( BlockId );
}

Std_ReturnType NvMService_InvalidateNvBlock(Nvm_BlockIdType BlockId) {
	return NvM_InvalidateNvBlock( BlockId );
}

Std_ReturnType NvMAdministration_SetBlockProtection(Nvm_BlockIdType BlockId, Boolean ProtectionEnabled) {
	NvM_SetBlockProtection( BlockId, (boolean)(ProtectionEnabled) );
	return E_OK;
}

#else

Std_ReturnType NvMService_EraseBlock(Nvm_BlockIdType BlockId) {
	/* Dummy */
	return E_OK;
}

Std_ReturnType NvMService_InvalidateNvBlock(Nvm_BlockIdType BlockId) {
	/* Dummy */
	return E_OK;
}

Std_ReturnType NvMAdministration_SetBlockProtection(Nvm_BlockIdType BlockId, Boolean ProtectionEnabled) {
	/* Dummy */
	return E_OK;
}

#endif

#endif /* CFG_NVM_USE_SERVICE_COMPONENT */
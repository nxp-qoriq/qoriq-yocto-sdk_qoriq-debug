/*
 * Copyright (C) 2010, 2011, 2012 Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * This software may be distributed under the terms of the
 * GNU General Public License ("GPL") as published by the Free Software
 * Foundation, either version 2 of that License or (at your option) any
 * later version.
 *
 * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "dcsr_nal.h"

/* Driver Initialization Function */
int dcsr_nal_init(struct dentry *parent_dentry, struct dbg_device *dev)
{
	struct dentry *current_dentry;
	struct dentry *de;
	struct nal *ptr = (struct nal *)dev->mem_ptr[0];

	CREATE_CURRENT_DBGFS_DIR(parent_dentry, dev,
					DEBUGFS_NAL_NAME);

	DBGFS_CREATE_RW_X32("nalgsr", current_dentry, &ptr->gsr);
	DBGFS_CREATE_RW_X32("nalesr", current_dentry, &ptr->esr);
	DBGFS_CREATE_RW_X32("nalgcr", current_dentry, &ptr->gcr);
	DBGFS_CREATE_RW_X32("naltcr", current_dentry, &ptr->tcr);

	return 0;
}

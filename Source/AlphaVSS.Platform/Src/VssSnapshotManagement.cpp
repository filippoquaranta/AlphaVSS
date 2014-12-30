/* Copyright (c) 2008-2009 Peter Palotas
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */
#include "stdafx.h"

#include "VssSnapshotManagement.h"
#include "VssDifferentialSoftwareSnapshotManagement.h"

#ifdef ALPHAVSS_HAS_SNAPSHOTMGMT

namespace Alphaleonis { namespace Win32 { namespace Vss
{
	VssSnapshotManagement::VssSnapshotManagement()
	{
		::IVssSnapshotMgmt *pMgmt = 0;
		CheckCom(CoCreateInstance(CLSID_VssSnapshotMgmt, NULL, CLSCTX_ALL, IID_IVssSnapshotMgmt, (void**)&(pMgmt)));		
		mSnapshotMgmt = pMgmt;
	}


	VssSnapshotManagement::~VssSnapshotManagement()
	{
		this->!VssSnapshotManagement();
	}

	VssSnapshotManagement::!VssSnapshotManagement()
	{
		if (mSnapshotMgmt != 0)
		{
			mSnapshotMgmt->Release();
			mSnapshotMgmt = 0;
		}

#ifdef ALPHAVSS_HAS_SNAPSHOTMGMT2
		if (mIVssSnapshotMgmt2 != 0)
		{
			mIVssSnapshotMgmt2->Release();
			mIVssSnapshotMgmt2 = 0;
		}
#endif
	}

	IVssDifferentialSoftwareSnapshotManagement^ VssSnapshotManagement::GetDifferentialSoftwareSnapshotManagementInterface()
	{
		// software-provider id is {b5946137-7b9f-4925-af80-51abd60b20d5}
		const VSS_ID ProviderId = { 0xb5946137, 0x7b9f, 0x4925, { 0xaf,0x80,0x51,0xab,0xd6,0xb,0x20,0xd5 } };
		IVssDifferentialSoftwareSnapshotMgmt* pDiffMgmt;
		CheckCom(mSnapshotMgmt->GetProviderMgmtInterface(ProviderId, IID_IVssDifferentialSoftwareSnapshotMgmt, (IUnknown**)&pDiffMgmt));
		return gcnew VssDifferentialSoftwareSnapshotManagement(pDiffMgmt);
	}

	Int64 VssSnapshotManagement::GetMinDiffAreaSize()
	{
#ifdef ALPHAVSS_HAS_SNAPSHOTMGMT2
		LONGLONG llMinDiffAreaSize;
		CheckCom(RequireIVssSnapshotMgmt2()->GetMinDiffAreaSize(&llMinDiffAreaSize));
		return llMinDiffAreaSize;
#else
		UnsupportedOs();
#endif
	}

}
}}

#endif

#include "pch.h"

namespace Alphaleonis { namespace Win32 { namespace Vss
{

   void ThrowException(HRESULT errorCode)
   {
      throw GetExceptionForHr(errorCode);
   }

   Exception ^ GetExceptionForHr(HRESULT errorCode)
   {
      switch (errorCode)
      {
      case E_ACCESSDENIED:
         return gcnew UnauthorizedAccessException();
      case E_INVALIDARG:
         return gcnew ArgumentException();
      case E_OUTOFMEMORY:
         return gcnew OutOfMemoryException();
      case E_NOTIMPL:
         return gcnew NotImplementedException(L"The requested operation is not supported on the current operating system or by the current provider.");
      case E_UNEXPECTED:
      case VSS_E_UNEXPECTED:
         return gcnew VssUnexpectedErrorException();
      case VSS_E_INVALID_XML_DOCUMENT:
         return gcnew VssInvalidXmlDocumentException();
      case VSS_E_BAD_STATE:
         return gcnew VssBadStateException();
      case VSS_E_OBJECT_NOT_FOUND:
         return gcnew VssObjectNotFoundException();
      case VSS_E_PROVIDER_VETO:
         return gcnew VssProviderVetoException();
      case VSS_E_UNEXPECTED_PROVIDER_ERROR:
         return gcnew VssUnexpectedProviderErrorException();
      case VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED:
         return gcnew VssMaximumNumberOfVolumesReachedException();
      case VSS_E_MAXIMUM_NUMBER_OF_SNAPSHOTS_REACHED:
         return gcnew VssMaximumNumberOfSnapshotsReachedException();
      case VSS_E_MAXIMUM_DIFFAREA_ASSOCIATIONS_REACHED:
         return gcnew VssMaximumDiffAreaAssociationsReachedException();
      case VSS_E_PROVIDER_NOT_REGISTERED:
         return gcnew VssProviderNotRegisteredException();
      case VSS_E_VOLUME_NOT_SUPPORTED:
         return gcnew VssVolumeNotSupportedException();
      case VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER:
         return gcnew VssVolumeNotSupportedByProviderException();
      case VSS_E_UNEXPECTED_WRITER_ERROR:
         return gcnew VssUnexpectedWriterErrorException();
      case VSS_E_INSUFFICIENT_STORAGE:
         return gcnew VssInsufficientStorageException();
      case VSS_E_FLUSH_WRITES_TIMEOUT:
         return gcnew VssFlushWritesTimeoutException();
      case VSS_E_HOLD_WRITES_TIMEOUT:
         return gcnew VssHoldWritesTimeoutException();
      case VSS_E_OBJECT_ALREADY_EXISTS:
         return gcnew VssObjectAlreadyExistsException();
         // Skip these if not supported
      case VSS_E_REBOOT_REQUIRED:
         return gcnew VssRebootRequiredException();
      case VSS_E_REVERT_IN_PROGRESS:
         return gcnew VssRevertInProgressException();
      case VSS_E_TRANSACTION_FREEZE_TIMEOUT:
         return gcnew VssTransactionFreezeTimeoutException();
      case VSS_E_TRANSACTION_THAW_TIMEOUT:
         return gcnew VssTransactionThawTimeoutException();
      case VSS_E_RESYNC_IN_PROGRESS:
         return gcnew VssResyncInProgressException();
      case VSS_E_SNAPSHOT_NOT_IN_SET:
         return gcnew VssSnapshotNotInSetException();
      case VSS_E_LEGACY_PROVIDER:
         return gcnew VssLegacyProviderException();
      case VSS_E_UNSELECTED_VOLUME:
         return gcnew VssUnselectedVolumeException();
      case VSS_E_CANNOT_REVERT_DISKID:
         return gcnew VssCannotRevertDiskIdException();
      case VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT:
         return gcnew VssInconsistentSnapshotWriterException();
      case VSS_E_WRITERERROR_OUTOFRESOURCES:
         return gcnew VssOutOfResourcesWriterException();
      case VSS_E_WRITERERROR_TIMEOUT:
         return gcnew VssTimeoutWriterException();
      case VSS_E_WRITERERROR_RETRYABLE:
         return gcnew VssRetryableWriterException();
      case VSS_E_WRITERERROR_NONRETRYABLE:
         return gcnew VssNonRetryableWriterException();
      case VSS_E_WRITER_NOT_RESPONDING:
         return gcnew VssWriterNotRespondingException();
      case VSS_E_WRITER_STATUS_NOT_AVAILABLE:
         return gcnew VssWriterStatusNotAvailableException();
      case VSS_E_WRITERERROR_PARTIAL_FAILURE:
         return gcnew VssPartialFailureWriterException();
      case VSS_E_UNSUPPORTED_CONTEXT:
         return gcnew VssUnsupportedContextException();
      case VSS_E_VOLUME_IN_USE:
         return gcnew VssVolumeInUseException();
      case VSS_E_SNAPSHOT_SET_IN_PROGRESS:
         return gcnew VssSnapshotSetInProgressException();
      default:
         return System::Runtime::InteropServices::Marshal::GetExceptionForHR(errorCode);
      }
   }

   void WaitCheckAndReleaseVssAsyncOperation(::IVssAsync *pAsync)
   {
      CComPtr<::IVssAsync> spAsync;
      spAsync.Attach(pAsync);
      CheckCom(spAsync->Wait());
      HRESULT hr;
      CheckCom(spAsync->QueryStatus(&hr, NULL));
      CheckCom(hr);
      if (hr == VSS_S_ASYNC_CANCELLED)
         throw gcnew OperationCanceledException();
   }
}	
} }

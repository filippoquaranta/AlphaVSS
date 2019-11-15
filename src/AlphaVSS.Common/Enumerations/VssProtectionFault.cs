

namespace Alphaleonis.Win32.Vss
{
   /// <summary>
   /// Defines the set of shadow copy protection faults. 
   /// A shadow copy protection fault occurs when the VSS service is unable to perform a copy-on-
   /// write operation to the shadow copy storage area (also called the diff area).
   /// </summary>
   public enum VssProtectionFault
   {
      /// <summary>
      /// No shadow copy protection fault has occurred.
      /// </summary>
      None = 0,
      /// <summary>
      /// The volume that contains the shadow copy storage area could not be found. Usually this fault means that the volume has not yet arrived in the system.
      /// </summary>
      DiffAreaMissing = 1,
      /// <summary>
      /// The volume that contains the shadow copy storage area could not be brought online because an I/O failure occurred.
      /// </summary>
      IOFailureDuringOnline = 2,
      /// <summary>
      /// The shadow copy metadata for the shadow copy storage area has been corrupted.
      /// </summary>
      MetadataCorruption = 3,
      /// <summary>
      /// A memory allocation failure occurred. This could be caused by a temporary low-memory condition that does not happen again after you clear the fault and restart the shadow copy operation.
      /// </summary>
      MemoryAllocationFailure = 4,
      /// <summary>
      /// A memory mapping failure occurred. This fault could mean that the page file is too small, or it could be caused by a low-memory condition.
      /// </summary>
      MappedMemoryFailure = 5,
      /// <summary>
      /// A read failure occurred during the copy-on-write operation when data was being copied from the live volume to the shadow copy storage area volume.
      /// </summary>
      CowReadFailure = 6,
      /// <summary>
      /// A read or write failure occurred during the copy-on-write operation when data was being copied from the live volume to the shadow copy storage area volume. One possible reason is that the shadow copy storage area volume has been removed from the system.
      /// </summary>
      CowWriteFailure = 7,
      /// <summary>
      /// This failure means that either the shadow copy storage area is full or the shadow copy storage area volume is full. 
      /// After clearing the protection fault, you can do one of the following:
      /// <list type="bullet">
      ///     <item><description>Delete unused shadow copy storage areas by calling the <see cref="IVssDifferentialSoftwareSnapshotManagement.DeleteUnusedDiffAreas"/> method.</description></item>
      ///     <item><description>Increase the shadow copy storage area maximum size for the volume by calling the <see cref="IVssDifferentialSoftwareSnapshotManagement.ChangeDiffAreaMaximumSize(string, string, long)"/> method.</description></item>
      /// </list>
      /// </summary>
      DiffAreaFull = 8,
      /// <summary>
      /// The size of the shadow copy storage area could not be increased because there was no longer enough space on the shadow copy storage area volume.
      /// </summary>
      GrowTooSlow = 9,
      /// <summary>
      /// The size of the shadow copy storage area could not be increased.
      /// </summary>
      GrowFailed = 10,
      /// <summary>
      /// An unexpected error occurred.
      /// </summary>
      DestroyAllSnapshots = 11,
      /// <summary>
      /// Either the shadow copy storage area files could not be opened or the shadow copy storage area volume could not be mounted because of a file system operation failure.
      /// </summary>
      FileSystemFailure = 12,
      /// <summary>
      /// A read or write failure occurred on the shadow copy storage area volume.
      /// </summary>
      IOFailure = 13,
      /// <summary>
      /// The shadow copy storage area volume was removed from the system or could not be accessed for some other reason.
      /// </summary>
      DiffAreaRemoved = 14,
      /// <summary>
      /// Another application attempted to write to the shadow copy storage area.
      /// </summary>
      ExternalWriterToDiffArea = 15
   }
}


using System;
using System.Collections.Generic;
using System.Runtime.Serialization;
using System.Text;

namespace Alphaleonis.Win32.Vss
{
   /// <summary>
   /// Exception indicating that the writer operation failed because of a time-out between the Freeze and Thaw events. The recommended way to 
   /// handle this error code is to wait ten minutes and then repeat the operation, up to three times.
   /// </summary>
   [Serializable]
   public class VssTimeoutWriterException : VssRetryableWriterException
   {
      /// <summary>
      /// Initializes a new instance of the <see cref="VssTimeoutWriterException"/> class.
      /// </summary>
      public VssTimeoutWriterException()
         : base(Alphaleonis.Win32.Vss.Resources.LocalizedStrings.VssTimeoutWriterExceptionMessage)
      {
      }

      /// <summary>
      /// Initializes a new instance of the <see cref="VssTimeoutWriterException"/> class.
      /// </summary>
      /// <param name="message">The message that describes the error</param>
      public VssTimeoutWriterException(string message) : base(message) { }

      /// <summary>
      /// Initializes a new instance of the <see cref="VssTimeoutWriterException"/> class.
      /// </summary>
      /// <param name="message">The message that describes the error</param>
      /// <param name="innerException">The exception that is the cause of the current exception.</param>
      public VssTimeoutWriterException(string message, Exception innerException) : base(message, innerException) { }

      /// <summary>
      /// Initializes a new instance of the <see cref="VssTimeoutWriterException"/> class.
      /// </summary>
      /// <param name="info">The <see cref="SerializationInfo"/> that holds the serialized object data about the exception being thrown.</param>
      /// <param name="context">The <see cref="StreamingContext"/> that contains contextual information about the source or destination.</param>
      /// <exception cref="ArgumentNullException">
      /// The <paramref name="info"/> parameter is <see langword="null"/>.
      /// </exception>
      /// <exception cref="SerializationException">
      /// The class name is <see langword="null"/> or <see cref="Exception.HResult"/> is zero (0).
      /// </exception>
      protected VssTimeoutWriterException(SerializationInfo info, StreamingContext context)
         : base(info, context) { }
   }
}

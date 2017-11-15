
Upon unsuccessful termination, the \code{*struct_ptr_ptr}
may contain partially decoded data. This data may be useful for debugging
(such as by using \code{asn_fprint()}).
Don't forget to discard the unused partially decoded data by calling
\code{ASN_STRUCT_FREE()} or \code{ASN_STRUCT_RESET()}.

The function returns a compound structure:
\begin{codesample}
typedef struct {
    enum {
        RC_OK,          /* Decoded successfully */
        RC_WMORE,       /* More data expected, call again */
        RC_FAIL         /* Failure to decode data */
    } code;             /* Result code */
    size_t consumed;    /* Number of bytes consumed */
} asn_dec_rval_t;
\end{codesample}

\noindent{}The \code{.code} member specifies the decoding outcome.

\begin{tabular}[h!]{ll}
\texttt{RC\_OK} & Decoded successfully and completely \\
\texttt{RC\_WMORE} & More data expected, call again \\
\texttt{RC\_FAIL} & Failed for good
\end{tabular}

\noindent{}The \code{.consumed} member specifies the amount of \code{buffer} data
that was used during parsing, irrespectively of the \code{.code}.


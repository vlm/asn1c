The return value is returned in a compound structure:
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

The \code{.code} member specifies the decoding outcome.

\begin{description}[labelindent=\parindent]
\item[RC\_OK] Decoded successfully and completely
\item[RC\_WMORE] More data expected, call again
\item[RC\_FAIL] Failed for good
\end{description}

The \code{.consumed} member specifies the amount of \code{buffer} data
that was used during parsing, irrespectively of the \code{.code}.


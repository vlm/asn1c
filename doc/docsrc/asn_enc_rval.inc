
The function returns a compound structure:

\begin{codesample}
typedef struct {
    ssize_t encoded;
    const asn_TYPE_descriptor_t *failed_type;
    const void *structure_ptr;
} asn_enc_rval_t;
\end{codesample}

\noindent{}In case of unsuccessful encoding, the \code{.encoded} member is set to -1 and
the other members of the compound structure point to where the encoding has
failed to proceed further.

In case encoding is successful, the \code{.encoded} member specifies the
size of the serialized output.

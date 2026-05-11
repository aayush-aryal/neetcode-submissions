class Solution:

    def encode(self, strs: List[str]) -> str:
        # join using a # why not?
        return "<W>".join(strs) if len(strs)>0 else "<EMPTY>"

    def decode(self, s: str) -> List[str]:
        if "<EMPTY>" == s:
            return []
        words=s.split("<W>")
        return words

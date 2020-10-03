class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:        
        result = set()
        def to_morse(s):
            return ''.join(mapp.get(i) for i in s)
        
        mapp = {'a': '.-',     'b': '-...',   'c': '-.-.', 
                'd': '-..',    'e': '.',      'f': '..-.',
                'g': '--.',    'h': '....',   'i': '..',
                'j': '.---',   'k': '-.-',    'l': '.-..',
                'm': '--',     'n': '-.',     'o': '---',
                'p': '.--.',   'q': '--.-',   'r': '.-.',
                's': '...',    't': '-',      'u': '..-',
                'v': '...-',   'w': '.--',    'x': '-..-',
                'y': '-.--',   'z': '--..',
                }
        
        
        for word in words:
            result.add(to_morse(word))
            
        return len(result)
        

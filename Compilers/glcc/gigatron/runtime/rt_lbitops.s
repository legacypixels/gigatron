def scope():

    def code0():
        nohop()
        label('_@_lcom')
        _LDI(0xffff);XORW(LAC);STW(LAC)
        _LDI(0xffff);XORW(LAC+2);STW(LAC+2)
        RET()

    module(name='rt_lcom.s',
           code=[ ('EXPORT', '_@_lcom'),
                  ('CODE', '_@_lcom', code0) ])

    def code1():
        nohop()
        label('_@_land')
        STW(T3);DEEK();ANDW(LAC);STW(LAC)
        LDI(2);ADDW(T3);DEEK();ANDW(LAC+2);STW(LAC+2)
        RET()

    module(name='rt_land.s',
           code=[ ('EXPORT', '_@_land'),
                  ('CODE', '_@_land', code1) ])

    def code2():
        nohop()
        label('_@_lor')
        STW(T3);DEEK();ORW(LAC);STW(LAC)
        LDI(2);ADDW(T3);DEEK();ORW(LAC+2);STW(LAC+2)
        RET()

    module(name='rt_lor.s',
           code=[ ('EXPORT', '_@_lor'),
                  ('CODE', '_@_lor', code2) ])

    def code3():
        nohop()
        label('_@_lxor')
        STW(T3);DEEK();XORW(LAC);STW(LAC)
        LDI(2);ADDW(T3);DEEK();XORW(LAC+2);STW(LAC+2)
        RET()

    module(name='rt_lxor.s',
           code=[ ('EXPORT', '_@_lxor'),
                  ('CODE', '_@_lxor', code3) ])

scope()

# Local Variables:
# mode: python
# indent-tabs-mode: ()
# End:

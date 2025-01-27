def scope():

    # LCMPS, LCMPU compare(LAC,[vAC])
    def code0():
        nohop()
        label('_@_lcmps')
        STW(T3);DEEK();STW(T0)
        LDI(2);ADDW(T3);DEEK();STW(T1)
        label('__@lcmps_t0t1')
        LDW(LAC+2)
        _CMPWS(T0+2)
        _BEQ('.lcmp1')
        RET()
        label('_@_lcmpu')
        STW(T3);DEEK();STW(T0)
        LDI(2);ADDW(T3);DEEK();STW(T1)
        label('__@lcmpu_t0t1')
        LDW(LAC+2)
        _CMPWU(T0+2)
        _BEQ('.lcmp1')
        RET()
        label('.lcmp1')
        LDW(LAC)
        _CMPWU(T0)
        RET()

    module(name='lcmp.s',
           code= [ ('EXPORT', '_@_lcmps'),
                   ('EXPORT', '_@_lcmpu'),
                   ('EXPORT', '__@lcmps_t0t1'),
                   ('EXPORT', '__@lcmpu_t0t1'),
                   ('CODE', '_@_lcmps', code0) ])


    # LCMPX: compare(LAC,[vAC]) for equality only
    def code1():
        nohop()
        label('_@_lcmpx')
        STW(T3);DEEK();XORW(LAC);_BNE('.lcmpx1')
        LDI(2);ADDW(T3);DEEK();XORW(LAC+2)
        label('.lcmpx1')
        RET()

    module(name='lcmpx.s',
           code= [ ('EXPORT', '_@_lcmpx'),
                   ('CODE', '_@_lcmpx', code1) ] )

scope()

# Local Variables:
# mode: python
# indent-tabs-mode: ()
# End:

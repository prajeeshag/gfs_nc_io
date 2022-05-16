
    subroutine O_DATA_OVERRIDE_(field_name, field, istrt, im, lan, override)
        character(len=*), intent(in) :: field_name
        real, intent(out), O_DIMENSION_ :: field
        integer, intent(in) :: istrt, im, lan
        logical, intent(out), optional :: override

        integer :: is, ie, js, je
#ifdef LEVS_
        real :: field1(size(field,1),1,size(field,2))
#else
        real :: field1(size(field,1),1)
#endif

        if (gfs_io_pe) return
        is = istrt; ie = istrt+im-1; js = lan; je = lan

        call data_override('GFS', field_name, field1, time=currtime, override=override, &
                is_in=is, ie_in=ie, js_in=js, je_in=je)

#ifdef LEVS_
        field = field1(:,1,:) 
#else
        field = field1(:,1) 
#endif

    end subroutine O_DATA_OVERRIDE_

{*******************************************************}
{                                                       }
{       Pascal Script Source File                       }
{       Run by RemObjects Pascal Script in CnWizards    }
{                                                       }
{       Generated by CnPack IDE Wizards                 }
{                                                       }
{*******************************************************}

procedure LogProp(Indent: Integer; const Parent, PropName, Kind, Value: string);
var
  Msg: string;
  i: Integer;
begin
  for i := 0 to Indent - 1 do
    Msg := Msg + '  ';
  if Parent <> '' then
    Msg := Msg + Parent + '.';
  Writeln(Format('%s%s: %s = %s', [Msg, PropName, Kind, Value]));
end;

procedure LogObject(Indent: Integer; const Parent: string; Inst: TObject);
var
  i: Integer;
  List: TStringList;
  Obj: TObject;
  Method: TMethod;
  S: string;
begin
  List := TStringList.Create;
  try
    GetPropList(Inst, tkAny, List);
    for i := 0 to List.Count - 1 do
    begin
      try
        case PropType(Inst, List[i]) of
          tkUnknown:
            begin
              LogProp(Indent, Parent, List[i], 'tkUnknown', 'Unknown');
            end;
          tkInteger:
            begin
              LogProp(Indent, Parent, List[i], 'tkInteger', IntToStr(GetOrdProp(Inst, List[i])));
            end;
          tkChar:
            begin
              LogProp(Indent, Parent, List[i], 'tkChar', IntToStr(GetOrdProp(Inst, List[i])));
            end;
          tkEnumeration:
            begin
              LogProp(Indent, Parent, List[i], 'tkEnumeration', GetEnumProp(Inst, List[i]));
            end;
          tkFloat:
            begin
              LogProp(Indent, Parent, List[i], 'tkFloat', FloatToStr(GetFloatProp(Inst, List[i])));
            end;
          tkString:
            begin
              LogProp(Indent, Parent, List[i], 'tkString', GetStrProp(Inst, List[i]));
            end;
          tkSet:
            begin
              LogProp(Indent, Parent, List[i], 'tkSet', GetSetProp(Inst, List[i], True));
            end;
          tkClass:
            begin
              Obj := GetObjectProp(Inst, List[i]);
              LogProp(Indent, Parent, List[i], 'tkClass', '');
              if Parent <> '' then
                S := Parent + '.' + List[i]
              else
                S := List[i];
              if Obj <> nil then
                LogObject(Indent + 1, S, Obj);
            end;
          tkMethod:
            begin
              Method := GetMethodProp(Inst, List[i]);
              LogProp(Indent, Parent, List[i], 'tkMethod', '$' + IntToHex(Method.Code, 8));
            end;
          tkWChar:
            begin
              LogProp(Indent, Parent, List[i], 'tkWChar', IntToStr(GetOrdProp(Inst, List[i])));
            end;
          tkLString:
            begin
              LogProp(Indent, Parent, List[i], 'tkLString', GetStrProp(Inst, List[i]));
            end;
          tkWString:
            begin
              LogProp(Indent, Parent, List[i], 'tkWString', GetStrProp(Inst, List[i]));
            end;
          tkVariant:
            begin
              LogProp(Indent, Parent, List[i], 'tkVariant', '');
            end;
          tkArray:
            begin
              LogProp(Indent, Parent, List[i], 'tkArray', '');
            end;
          tkRecord:
            begin
              LogProp(Indent, Parent, List[i], 'tkRecord', '');
            end;
          tkInterface:
            begin
              LogProp(Indent, Parent, List[i], 'tkInterface', '');
            end;
          tkInt64:
            begin
              LogProp(Indent, Parent, List[i], 'tkInt64', Int64ToStr(GetInt64Prop(Inst, List[i])));
            end;
          tkDynArray:
            begin
              LogProp(Indent, Parent, List[i], 'tkDynArray', '');
            end;
        end;
      except
        ;
      end;                      
    end;
  finally
    List.Free;
  end;
end;


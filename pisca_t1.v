module pisca(input ent, output saida);

  assign saida = ent;
        
endmodule



module teste;
  reg ent;
  wire saida;

pisca A(ent, saida);
  always #1 ent <= ~ent;
  
  initial begin
    $dumpvars(0,A);
      #1 
      ent<= 0;
      #500
      $finish;
    end
endmodule

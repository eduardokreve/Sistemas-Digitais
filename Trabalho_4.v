//Baseado no exemplo do Professor e colegas.

module sign(
    input [11:0]px,
    input [11:0]py,
    input [11:0]x1,
    input [11:0]y1,
    input [11:0]x2,
    input [11:0]y2,
    output A
);

wire signed [11:0] r1;
wire signed [11:0] r2;
wire signed [11:0] r3;
wire signed [11:0] r4;
wire signed [23:0] m1;
wire signed [23:0] m2;

  assign r1 = px - x2;
  assign r2 = y1 - y2;
  assign r3 = x1 - x2;
  assign r4 = py - y2;
  assign m1 = r1 * r2;
  assign m2 = r3 * r4;

  assign A = m1 < m2;
endmodule

module triangle(
  input [11:0] px,
  input [11:0] py,
  input [11:0] x1,
  input [11:0] y1,
  input [11:0] x2,
  input [11:0] y2,
  input [11:0] x3,
  input [11:0] y3,
  output saida
);


wire s1, s2, s3;

sign st1(px, py, x1, y1, x2, y2, s1);
sign st2(px, py, x2, y2, x3, y3, s2);
sign st3(px, py, x3, y3, x1, y1, s3);

assign saida = s1 == s2 & s2 == s3;

endmodule

module execucao;

integer ler;
integer escrever;
integer valor;

reg signed [11:0] px;
reg signed [11:0] py;
reg signed [11:0] x1;
reg signed [11:0] y1;
reg signed [11:0] x2;
reg signed [11:0] y2;
reg signed [11:0] x3;
reg signed [11:0] y3;
wire saida;
reg state = 0;
triangle T(px, py, x1, y1, x2, y2, x3, y3, saida);

initial begin
  ler = $fopen("coordenadas.txt", "r");
  escrever = $fopen("resultado_V.txt", "w");
end

always #2 begin
  if (!$feof(ler)) begin
	  if (state != 0)begin

	    $fdisplay(escrever, "%d", saida);

	    valor = $fscanf(ler, "%d %d %d %d %d %d %d %d\n",
	      px, py, x1, y1, x2, y2, x3, y3);
	  end else begin
		valor = $fscanf(ler, "%d %d %d %d %d %d %d %d\n",
	      px, py, x1, y1, x2, y2, x3, y3);
		state = 1;
  	end
  end
  else begin
    $finish;
  end
end

endmodule

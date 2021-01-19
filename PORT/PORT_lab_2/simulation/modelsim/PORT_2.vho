-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"

-- DATE "08/27/2020 01:43:56"

-- 
-- Device: Altera EP3C16F484C6 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	PORT_2 IS
    PORT (
	HEX0_0 : OUT std_logic;
	clk : IN std_logic;
	btn0 : IN std_logic;
	btn1 : IN std_logic;
	HEX0_1 : OUT std_logic;
	HEX0_2 : OUT std_logic;
	HEX0_3 : OUT std_logic;
	HEX0_4 : OUT std_logic;
	HEX0_5 : OUT std_logic;
	HEX0_6 : OUT std_logic;
	HEX0_7 : OUT std_logic
	);
END PORT_2;

-- Design Ports Information
-- HEX0_0	=>  Location: PIN_E11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_1	=>  Location: PIN_F11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_2	=>  Location: PIN_H12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_3	=>  Location: PIN_H13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_4	=>  Location: PIN_G12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_5	=>  Location: PIN_F12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_6	=>  Location: PIN_F13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HEX0_7	=>  Location: PIN_D13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- btn0	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- btn1	=>  Location: PIN_G3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_G21,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF PORT_2 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_HEX0_0 : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_btn0 : std_logic;
SIGNAL ww_btn1 : std_logic;
SIGNAL ww_HEX0_1 : std_logic;
SIGNAL ww_HEX0_2 : std_logic;
SIGNAL ww_HEX0_3 : std_logic;
SIGNAL ww_HEX0_4 : std_logic;
SIGNAL ww_HEX0_5 : std_logic;
SIGNAL ww_HEX0_6 : std_logic;
SIGNAL ww_HEX0_7 : std_logic;
SIGNAL \clk~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \HEX0_0~output_o\ : std_logic;
SIGNAL \HEX0_1~output_o\ : std_logic;
SIGNAL \HEX0_2~output_o\ : std_logic;
SIGNAL \HEX0_3~output_o\ : std_logic;
SIGNAL \HEX0_4~output_o\ : std_logic;
SIGNAL \HEX0_5~output_o\ : std_logic;
SIGNAL \HEX0_6~output_o\ : std_logic;
SIGNAL \HEX0_7~output_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \btn1~input_o\ : std_logic;
SIGNAL \btn0~input_o\ : std_logic;
SIGNAL \inst|state[1]~0_combout\ : std_logic;
SIGNAL \inst2~0_combout\ : std_logic;
SIGNAL \inst1|state[1]~0_combout\ : std_logic;
SIGNAL \inst4~combout\ : std_logic;
SIGNAL \random|inst5~0_combout\ : std_logic;
SIGNAL \random|inst6~0_combout\ : std_logic;
SIGNAL \random|inst6~q\ : std_logic;
SIGNAL \random|or6~0_combout\ : std_logic;
SIGNAL \random|tff1~0_combout\ : std_logic;
SIGNAL \random|tff1~q\ : std_logic;
SIGNAL \random|tff2~0_combout\ : std_logic;
SIGNAL \random|tff2~1_combout\ : std_logic;
SIGNAL \random|tff2~q\ : std_logic;
SIGNAL \random|or4~1_combout\ : std_logic;
SIGNAL \random|or4~0_combout\ : std_logic;
SIGNAL \random|or4~2_combout\ : std_logic;
SIGNAL \random|or7~0_combout\ : std_logic;
SIGNAL \random|or7~1_combout\ : std_logic;
SIGNAL \random|or5~0_combout\ : std_logic;
SIGNAL \random|or5~1_combout\ : std_logic;
SIGNAL \inst5|Mux0~0_combout\ : std_logic;
SIGNAL \inst5|Mux1~0_combout\ : std_logic;
SIGNAL \inst5|Mux2~0_combout\ : std_logic;
SIGNAL \inst5|Mux3~0_combout\ : std_logic;
SIGNAL \inst5|Mux4~0_combout\ : std_logic;
SIGNAL \inst5|Mux5~0_combout\ : std_logic;
SIGNAL \inst5|Mux6~0_combout\ : std_logic;
SIGNAL \inst1|state\ : std_logic_vector(1 DOWNTO 0);
SIGNAL \inst|state\ : std_logic_vector(1 DOWNTO 0);

BEGIN

HEX0_0 <= ww_HEX0_0;
ww_clk <= clk;
ww_btn0 <= btn0;
ww_btn1 <= btn1;
HEX0_1 <= ww_HEX0_1;
HEX0_2 <= ww_HEX0_2;
HEX0_3 <= ww_HEX0_3;
HEX0_4 <= ww_HEX0_4;
HEX0_5 <= ww_HEX0_5;
HEX0_6 <= ww_HEX0_6;
HEX0_7 <= ww_HEX0_7;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\clk~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clk~input_o\);

-- Location: IOOBUF_X21_Y29_N23
\HEX0_0~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux0~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_0~output_o\);

-- Location: IOOBUF_X21_Y29_N30
\HEX0_1~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux1~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_1~output_o\);

-- Location: IOOBUF_X26_Y29_N2
\HEX0_2~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux2~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_2~output_o\);

-- Location: IOOBUF_X28_Y29_N30
\HEX0_3~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux3~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_3~output_o\);

-- Location: IOOBUF_X26_Y29_N9
\HEX0_4~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux4~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_4~output_o\);

-- Location: IOOBUF_X28_Y29_N23
\HEX0_5~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux5~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_5~output_o\);

-- Location: IOOBUF_X26_Y29_N16
\HEX0_6~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst5|Mux6~0_combout\,
	devoe => ww_devoe,
	o => \HEX0_6~output_o\);

-- Location: IOOBUF_X23_Y29_N9
\HEX0_7~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \HEX0_7~output_o\);

-- Location: IOIBUF_X41_Y15_N1
\clk~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: CLKCTRL_G9
\clk~inputclkctrl\ : cycloneiii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clk~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clk~inputclkctrl_outclk\);

-- Location: IOIBUF_X0_Y23_N15
\btn1~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_btn1,
	o => \btn1~input_o\);

-- Location: IOIBUF_X0_Y21_N8
\btn0~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_btn0,
	o => \btn0~input_o\);

-- Location: LCCOMB_X26_Y28_N6
\inst|state[1]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|state[1]~0_combout\ = !\btn0~input_o\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \btn0~input_o\,
	combout => \inst|state[1]~0_combout\);

-- Location: FF_X26_Y28_N7
\inst|state[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \inst|state[1]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|state\(1));

-- Location: FF_X26_Y28_N27
\inst|state[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	asdata => \inst|state\(1),
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|state\(0));

-- Location: LCCOMB_X26_Y28_N26
\inst2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2~0_combout\ = (\btn1~input_o\ & (((\inst|state\(0)) # (!\inst|state\(1))))) # (!\btn1~input_o\ & (\btn0~input_o\ & ((\inst|state\(0)) # (!\inst|state\(1)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \btn1~input_o\,
	datab => \btn0~input_o\,
	datac => \inst|state\(0),
	datad => \inst|state\(1),
	combout => \inst2~0_combout\);

-- Location: LCCOMB_X26_Y28_N30
\inst1|state[1]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst1|state[1]~0_combout\ = !\btn1~input_o\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \btn1~input_o\,
	combout => \inst1|state[1]~0_combout\);

-- Location: FF_X26_Y28_N31
\inst1|state[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \inst1|state[1]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|state\(1));

-- Location: FF_X26_Y28_N25
\inst1|state[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	asdata => \inst1|state\(1),
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst1|state\(0));

-- Location: LCCOMB_X26_Y28_N2
inst4 : cycloneiii_lcell_comb
-- Equation(s):
-- \inst4~combout\ = (\btn1~input_o\ & (((\inst1|state\(1) & !\inst1|state\(0))))) # (!\btn1~input_o\ & (((\inst1|state\(1) & !\inst1|state\(0))) # (!\btn0~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111110001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \btn1~input_o\,
	datab => \btn0~input_o\,
	datac => \inst1|state\(1),
	datad => \inst1|state\(0),
	combout => \inst4~combout\);

-- Location: LCCOMB_X26_Y28_N10
\random|inst5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|inst5~0_combout\ = (\random|inst6~q\ & (!\random|tff2~q\)) # (!\random|inst6~q\ & ((!\random|tff1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000000111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \random|tff2~q\,
	datac => \random|inst6~q\,
	datad => \random|tff1~q\,
	combout => \random|inst5~0_combout\);

-- Location: LCCOMB_X26_Y28_N4
\random|inst6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|inst6~0_combout\ = (\inst2~0_combout\ & (\random|inst6~q\ $ (((\inst4~combout\ & !\random|inst5~0_combout\))))) # (!\inst2~0_combout\ & (\inst4~combout\ & (\random|inst6~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000001101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2~0_combout\,
	datab => \inst4~combout\,
	datac => \random|inst6~q\,
	datad => \random|inst5~0_combout\,
	combout => \random|inst6~0_combout\);

-- Location: FF_X26_Y28_N5
\random|inst6\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \random|inst6~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \random|inst6~q\);

-- Location: LCCOMB_X26_Y28_N12
\random|or6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or6~0_combout\ = (\random|tff1~q\ & ((\random|tff2~q\) # (!\random|inst6~q\))) # (!\random|tff1~q\ & ((\random|inst6~q\) # (!\random|tff2~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \random|tff1~q\,
	datac => \random|inst6~q\,
	datad => \random|tff2~q\,
	combout => \random|or6~0_combout\);

-- Location: LCCOMB_X26_Y28_N28
\random|tff1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|tff1~0_combout\ = (\inst2~0_combout\ & (\random|tff1~q\ $ (((\inst4~combout\ & \random|or6~0_combout\))))) # (!\inst2~0_combout\ & (\inst4~combout\ & (\random|tff1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100011100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2~0_combout\,
	datab => \inst4~combout\,
	datac => \random|tff1~q\,
	datad => \random|or6~0_combout\,
	combout => \random|tff1~0_combout\);

-- Location: FF_X26_Y28_N29
\random|tff1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \random|tff1~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \random|tff1~q\);

-- Location: LCCOMB_X26_Y28_N20
\random|tff2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|tff2~0_combout\ = (\random|tff2~q\ & ((\inst2~0_combout\ & ((\random|inst6~q\) # (!\inst4~combout\))) # (!\inst2~0_combout\ & ((\inst4~combout\))))) # (!\random|tff2~q\ & (((\inst2~0_combout\ & \inst4~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|tff2~q\,
	datab => \random|inst6~q\,
	datac => \inst2~0_combout\,
	datad => \inst4~combout\,
	combout => \random|tff2~0_combout\);

-- Location: LCCOMB_X26_Y28_N18
\random|tff2~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|tff2~1_combout\ = (\random|tff2~0_combout\ & ((\random|tff1~q\) # (\random|tff2~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \random|tff1~q\,
	datac => \random|tff2~q\,
	datad => \random|tff2~0_combout\,
	combout => \random|tff2~1_combout\);

-- Location: FF_X26_Y28_N19
\random|tff2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \random|tff2~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \random|tff2~q\);

-- Location: LCCOMB_X26_Y28_N8
\random|or4~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or4~1_combout\ = (\random|inst6~q\ & (!\random|tff2~q\)) # (!\random|inst6~q\ & (((\inst4~combout\ & \random|tff1~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101110001010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|tff2~q\,
	datab => \inst4~combout\,
	datac => \random|inst6~q\,
	datad => \random|tff1~q\,
	combout => \random|or4~1_combout\);

-- Location: LCCOMB_X26_Y28_N22
\random|or4~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or4~0_combout\ = (\inst2~0_combout\ & (((\inst1|state\(0))) # (!\inst1|state\(1)))) # (!\inst2~0_combout\ & (((\inst4~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101001110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst2~0_combout\,
	datab => \inst1|state\(1),
	datac => \inst4~combout\,
	datad => \inst1|state\(0),
	combout => \random|or4~0_combout\);

-- Location: LCCOMB_X26_Y28_N0
\random|or4~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or4~2_combout\ = (\random|or4~1_combout\ & ((\inst2~0_combout\) # ((\random|inst6~q\ & \random|or4~0_combout\)))) # (!\random|or4~1_combout\ & (\random|inst6~q\ & (\random|or4~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110101011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~1_combout\,
	datab => \random|inst6~q\,
	datac => \random|or4~0_combout\,
	datad => \inst2~0_combout\,
	combout => \random|or4~2_combout\);

-- Location: LCCOMB_X26_Y28_N24
\random|or7~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or7~0_combout\ = (\random|tff2~q\ & (\random|inst6~q\)) # (!\random|tff2~q\ & ((\random|tff1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110110001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|tff2~q\,
	datab => \random|inst6~q\,
	datad => \random|tff1~q\,
	combout => \random|or7~0_combout\);

-- Location: LCCOMB_X26_Y28_N16
\random|or7~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or7~1_combout\ = (\inst4~combout\ & ((\inst2~0_combout\ & ((\random|or7~0_combout\))) # (!\inst2~0_combout\ & (\random|tff2~q\)))) # (!\inst4~combout\ & (\random|tff2~q\ & ((\inst2~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110001010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|tff2~q\,
	datab => \inst4~combout\,
	datac => \random|or7~0_combout\,
	datad => \inst2~0_combout\,
	combout => \random|or7~1_combout\);

-- Location: LCCOMB_X26_Y28_N14
\random|or5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or5~0_combout\ = (\random|inst6~q\ & ((!\random|tff1~q\) # (!\random|tff2~q\))) # (!\random|inst6~q\ & (!\random|tff2~q\ & !\random|tff1~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000110011001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \random|inst6~q\,
	datac => \random|tff2~q\,
	datad => \random|tff1~q\,
	combout => \random|or5~0_combout\);

-- Location: LCCOMB_X27_Y28_N12
\random|or5~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \random|or5~1_combout\ = (\inst2~0_combout\ & ((\inst4~combout\ & (\random|or5~0_combout\)) # (!\inst4~combout\ & ((\random|tff1~q\))))) # (!\inst2~0_combout\ & (((\inst4~combout\ & \random|tff1~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011110010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or5~0_combout\,
	datab => \inst2~0_combout\,
	datac => \inst4~combout\,
	datad => \random|tff1~q\,
	combout => \random|or5~1_combout\);

-- Location: LCCOMB_X27_Y28_N26
\inst5|Mux0~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux0~0_combout\ = (!\random|or5~1_combout\ & (\random|or4~2_combout\ $ (\random|or7~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux0~0_combout\);

-- Location: LCCOMB_X27_Y28_N20
\inst5|Mux1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux1~0_combout\ = (\random|or4~2_combout\ & (\random|or7~1_combout\ $ (\random|or5~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux1~0_combout\);

-- Location: LCCOMB_X27_Y28_N2
\inst5|Mux2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux2~0_combout\ = (!\random|or4~2_combout\ & (!\random|or7~1_combout\ & \random|or5~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux2~0_combout\);

-- Location: LCCOMB_X27_Y28_N0
\inst5|Mux3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux3~0_combout\ = (\random|or4~2_combout\ & (\random|or7~1_combout\ $ (!\random|or5~1_combout\))) # (!\random|or4~2_combout\ & (\random|or7~1_combout\ & !\random|or5~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000001011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux3~0_combout\);

-- Location: LCCOMB_X27_Y28_N22
\inst5|Mux4~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux4~0_combout\ = (\random|or7~1_combout\) # ((\random|or4~2_combout\ & !\random|or5~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux4~0_combout\);

-- Location: LCCOMB_X27_Y28_N16
\inst5|Mux5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux5~0_combout\ = (\random|or4~2_combout\ & (\random|or7~1_combout\ & \random|or5~1_combout\)) # (!\random|or4~2_combout\ & ((\random|or7~1_combout\) # (\random|or5~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010101010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux5~0_combout\);

-- Location: LCCOMB_X27_Y28_N10
\inst5|Mux6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst5|Mux6~0_combout\ = (\random|or4~2_combout\ & (\random|or7~1_combout\ & \random|or5~1_combout\)) # (!\random|or4~2_combout\ & ((!\random|or5~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000001010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \random|or4~2_combout\,
	datac => \random|or7~1_combout\,
	datad => \random|or5~1_combout\,
	combout => \inst5|Mux6~0_combout\);

ww_HEX0_0 <= \HEX0_0~output_o\;

ww_HEX0_1 <= \HEX0_1~output_o\;

ww_HEX0_2 <= \HEX0_2~output_o\;

ww_HEX0_3 <= \HEX0_3~output_o\;

ww_HEX0_4 <= \HEX0_4~output_o\;

ww_HEX0_5 <= \HEX0_5~output_o\;

ww_HEX0_6 <= \HEX0_6~output_o\;

ww_HEX0_7 <= \HEX0_7~output_o\;
END structure;



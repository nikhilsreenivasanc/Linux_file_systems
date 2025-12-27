Module                  Size  Used by
device_file            12288  0
hid_generic            12288  0
vboxnetadp             28672  0
vboxnetflt             36864  0
vboxdrv               696320  2 vboxnetadp,vboxnetflt
ccm                    20480  6
rfcomm                102400  16
cmac                   12288  3
algif_hash             12288  1
algif_skcipher         16384  1
af_alg                 32768  6 algif_hash,algif_skcipher
bnep                   32768  2
snd_sof_pci_intel_skl    12288  0
snd_sof_intel_hda_common   217088  1 snd_sof_pci_intel_skl
soundwire_intel        73728  1 snd_sof_intel_hda_common
snd_sof_intel_hda_mlink    45056  2 soundwire_intel,snd_sof_intel_hda_common
soundwire_cadence      45056  1 soundwire_intel
snd_sof_intel_hda      24576  1 snd_sof_intel_hda_common
snd_sof_pci            24576  2 snd_sof_intel_hda_common,snd_sof_pci_intel_skl
snd_sof_xtensa_dsp     12288  1 snd_sof_intel_hda_common
snd_sof               380928  3 snd_sof_pci,snd_sof_intel_hda_common,snd_sof_intel_hda
snd_hda_codec_hdmi     94208  1
snd_sof_utils          16384  1 snd_sof
soundwire_generic_allocation    12288  1 soundwire_intel
soundwire_bus         110592  3 soundwire_intel,soundwire_generic_allocation,soundwire_cadence
snd_soc_avs           188416  0
snd_ctl_led            24576  0
snd_hda_codec_realtek   200704  1
snd_hda_codec_generic   122880  1 snd_hda_codec_realtek
snd_soc_hda_codec      24576  1 snd_soc_avs
intel_rapl_msr         20480  0
intel_rapl_common      40960  1 intel_rapl_msr
intel_pmc_core_pltdrv    12288  0
intel_pmc_core        118784  0
intel_vsec             20480  1 intel_pmc_core
pmt_telemetry          16384  1 intel_pmc_core
pmt_class              12288  1 pmt_telemetry
snd_soc_skl           208896  0
intel_tcc_cooling      12288  0
snd_soc_hdac_hda       24576  2 snd_sof_intel_hda_common,snd_soc_skl
snd_hda_ext_core       32768  7 snd_soc_avs,snd_soc_hda_codec,snd_sof_intel_hda_common,snd_soc_hdac_hda,snd_sof_intel_hda_mlink,snd_soc_skl,snd_sof_intel_hda
x86_pkg_temp_thermal    20480  0
snd_soc_sst_ipc        20480  1 snd_soc_skl
intel_powerclamp       24576  0
snd_soc_sst_dsp        36864  1 snd_soc_skl
snd_soc_acpi_intel_match    98304  3 snd_sof_intel_hda_common,snd_soc_skl,snd_sof_pci_intel_skl
coretemp               24576  0
snd_soc_acpi           16384  3 snd_soc_acpi_intel_match,snd_sof_intel_hda_common,snd_soc_skl
snd_soc_core          442368  7 snd_soc_avs,snd_soc_hda_codec,soundwire_intel,snd_sof,snd_sof_intel_hda_common,snd_soc_hdac_hda,snd_soc_skl
kvm_intel             487424  0
snd_compress           28672  2 snd_soc_avs,snd_soc_core
ac97_bus               12288  1 snd_soc_core
snd_pcm_dmaengine      16384  1 snd_soc_core
kvm                  1413120  1 kvm_intel
irqbypass              12288  1 kvm
snd_hda_intel          61440  3
crct10dif_pclmul       12288  1
snd_intel_dspcfg       36864  5 snd_soc_avs,snd_hda_intel,snd_sof,snd_sof_intel_hda_common,snd_soc_skl
polyval_clmulni        12288  0
snd_intel_sdw_acpi     16384  2 snd_sof_intel_hda_common,snd_intel_dspcfg
binfmt_misc            24576  1
snd_hda_codec         204800  9 snd_hda_codec_generic,snd_soc_avs,snd_hda_codec_hdmi,snd_soc_hda_codec,snd_hda_intel,snd_hda_codec_realtek,snd_soc_hdac_hda,snd_soc_skl,snd_sof_intel_hda
polyval_generic        12288  1 polyval_clmulni
ghash_clmulni_intel    16384  0
uvcvideo              147456  0
snd_hda_core          139264  12 snd_hda_codec_generic,snd_soc_avs,snd_hda_codec_hdmi,snd_soc_hda_codec,snd_hda_intel,snd_hda_ext_core,snd_hda_codec,snd_hda_codec_realtek,snd_sof_intel_hda_common,snd_soc_hdac_hda,snd_soc_skl,snd_sof_intel_hda
sha256_ssse3           32768  0
snd_hwdep              20480  1 snd_hda_codec
videobuf2_vmalloc      20480  1 uvcvideo
uvc                    12288  1 uvcvideo
sha1_ssse3             32768  0
aesni_intel           356352  8
snd_pcm               192512  13 snd_soc_avs,snd_hda_codec_hdmi,snd_hda_intel,snd_hda_codec,soundwire_intel,snd_sof,snd_sof_intel_hda_common,snd_compress,snd_soc_core,snd_sof_utils,snd_soc_skl,snd_hda_core,snd_pcm_dmaengine
videobuf2_memops       16384  1 videobuf2_vmalloc
btusb                  77824  0
crypto_simd            16384  1 aesni_intel
videobuf2_v4l2         36864  1 uvcvideo
cryptd                 24576  3 crypto_simd,ghash_clmulni_intel
mei_pxp                16384  0
btrtl                  32768  1 btusb
rapl                   20480  0
btintel                57344  1 btusb
iwlmvm                872448  0
videodev              356352  2 videobuf2_v4l2,uvcvideo
snd_seq_midi           24576  0
btbcm                  24576  1 btusb
mei_hdcp               28672  0
nls_iso8859_1          12288  1
intel_cstate           24576  0
input_leds             12288  0
joydev                 32768  0
btmtk                  12288  1 btusb
videobuf2_common       81920  4 videobuf2_vmalloc,videobuf2_v4l2,uvcvideo,videobuf2_memops
i915                 4300800  33
mc                     81920  4 videodev,videobuf2_v4l2,uvcvideo,videobuf2_common
snd_seq_midi_event     16384  1 snd_seq_midi
mac80211             1753088  1 iwlmvm
bluetooth            1032192  44 btrtl,btmtk,btintel,btbcm,bnep,btusb,rfcomm
snd_rawmidi            57344  1 snd_seq_midi
libarc4                12288  1 mac80211
ecdh_generic           16384  2 bluetooth
serio_raw              20480  0
snd_seq               118784  2 snd_seq_midi,snd_seq_midi_event
drm_buddy              20480  1 i915
ecc                    45056  1 ecdh_generic
iwlwifi               606208  1 iwlmvm
ttm                   110592  1 i915
drm_display_helper    237568  1 i915
think_lmi              45056  0
snd_seq_device         16384  3 snd_seq,snd_seq_midi,snd_rawmidi
wmi_bmof               12288  0
cec                    94208  2 drm_display_helper,i915
thinkpad_acpi         163840  0
firmware_attributes_class    12288  1 think_lmi
intel_wmi_thunderbolt    16384  0
snd_timer              49152  2 snd_seq,snd_pcm
mei_me                 53248  2
cfg80211             1363968  3 iwlmvm,iwlwifi,mac80211
ee1004                 16384  0
nvram                  16384  1 thinkpad_acpi
rc_core                73728  1 cec
i2c_algo_bit           16384  1 i915
mei                   167936  5 mei_hdcp,mei_pxp,mei_me
snd                   143360  22 snd_ctl_led,snd_hda_codec_generic,snd_seq,snd_seq_device,snd_hda_codec_hdmi,snd_hwdep,snd_hda_intel,snd_hda_codec,snd_hda_codec_realtek,snd_sof,snd_timer,snd_compress,thinkpad_acpi,snd_soc_core,snd_pcm,snd_rawmidi
intel_xhci_usb_role_switch    12288  0
intel_pch_thermal      20480  0
soundcore              16384  2 snd_ctl_led,snd
ledtrig_audio          12288  2 snd_ctl_led,thinkpad_acpi
platform_profile       12288  1 thinkpad_acpi
acpi_pad              184320  0
mac_hid                12288  0
sch_fq_codel           24576  2
msr                    12288  0
parport_pc             53248  0
ppdev                  24576  0
lp                     28672  0
parport                73728  3 parport_pc,lp,ppdev
efi_pstore             12288  0
ip_tables              32768  0
x_tables               65536  1 ip_tables
autofs4                57344  2
uas                    28672  0
usbhid                 77824  0
usb_storage            86016  1 uas
hid                   180224  2 usbhid,hid_generic
video                  77824  2 thinkpad_acpi,i915
crc32_pclmul           12288  0
psmouse               217088  0
e1000e                356352  0
i2c_i801               36864  0
i2c_smbus              16384  1 i2c_i801
ucsi_acpi              12288  0
typec_ucsi             61440  1 ucsi_acpi
xhci_pci               24576  0
ahci                   49152  2
libahci                53248  1 ahci
xhci_pci_renesas       20480  1 xhci_pci
typec                 106496  1 typec_ucsi
wmi                    28672  4 video,intel_wmi_thunderbolt,wmi_bmof,think_lmi
